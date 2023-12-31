#include "yolo.h"

YOLO::YOLO(my_Configuration config, bool ifcuda, string classnamespath)
{
	this->confThreshold = config.confThreshold;
	this->nmsThreshold = config.nmsThreshold;
	this->objThreshold = config.objThreshold;
	this->width_ = 640;
	this->height_ = 640;
	read_classnames(classnamespath, this->class_names);
	this->num_classes = class_names.size();

	srand(time(0));
	for (int i = 0; i < 80; i++) {
		int b = rand() % 256;
		int g = rand() % 256;
		int r = rand() % 256;
		color.push_back(cv::Scalar(b, g, r));
	}

	if (ifcuda) {
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
	}
	//cpu
	else {
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
	}

	this->net = cv::dnn::readNet(config.modelpath);
}

float YOLO::sigmoid(float x)
{
	return 1 / (1 + exp(-x));
}

void YOLO::read_classnames(string classnamespath, std::vector<std::string>& class_names)
{
	//std::vector<std::string> class_names;
	ifstream ifs(string(classnamespath).c_str());
	string line;
	while (getline(ifs, line))
	{
		class_names.push_back(line);
	}
}

cv::Mat YOLO::resize_image(cv::Mat srcimage, int wigth, int height)
{

	cv::Mat img;
	if (srcimage.rows != wigth && srcimage.cols != height)
	{
		resize(srcimage, img, cv::Size(wigth, height), cv::INTER_AREA);  //���ĸ�����Ϊ��ֵ����
	}
	else
	{
		return srcimage;
	}
	return img;
}

void YOLO::detect(cv::Mat& image, vector<Output>& output)
{
	cv::Mat dstimg = resize_image(image, this->width_, this->height_);
	cv::Mat blob = cv::dnn::blobFromImage(dstimg, 1/255.0, cv::Size(this->width_, this->height_), cv::Scalar(0, 0, 0), true, false);
	this->net.setInput(blob);
	vector<cv::Mat> outs;
	this->net.forward(outs, this->net.getUnconnectedOutLayersNames());
	//ÿ�㶼�о��ο� ������� ���Ŷ�
	vector<cv::Rect> boxes;
	vector<int> classIds;
	vector<float> confidences;
	float ratioh = (float)image.rows / this->height_;  //�õ������ԭͼ�����ű���
	float ratiow = (float)image.cols / this->width_;
	int net_width = num_classes + 5;  //�����+5
	for (size_t stride = 0; stride < outs.size(); stride++)//����3��������
	{	
		float* pdata = (float*)outs[stride].data;
		int grid_x = (int)(width_ / netStride[stride]);//8 16 32 
		int grid_y = (int)(height_ / netStride[stride]);
		for (int anchor = 0; anchor < 3; anchor++)
		{
			const float anchor_w = yolo_anthors[stride][anchor * 2];  //�õ�ê��
			const float anchor_h = yolo_anthors[stride][anchor * 2 + 1];
			for (int i = 0; i < grid_y; i++)
			{
				for (int j = 0; j < grid_x; j++)
				{
					float obj_conf = sigmoid(pdata[4]);  //��������ĸ���
					if (obj_conf > this->objThreshold)
					{
						cv::Mat scores(1, num_classes, CV_32FC1, pdata + 5);
						cv::Point classIdPoint;   //���ֵλ��
						double max_class_socre;    //��ȡ�������Ӧ������ֵ
						cv::minMaxLoc(scores, 0, &max_class_socre, 0, &classIdPoint);
						max_class_socre = sigmoid(max_class_socre);
						if (max_class_socre > this->confThreshold)
						{
							float x = (sigmoid(pdata[0]) * 2.f - 0.5f + j) * netStride[stride];  //x
							float y = (sigmoid(pdata[1]) * 2.f - 0.5f + i) * netStride[stride];   //y
							float w = powf(sigmoid(pdata[2]) * 2.f, 2.f) * anchor_w;   //w
							float h = powf(sigmoid(pdata[3]) * 2.f, 2.f) * anchor_h;  //h
							int left = (int)(x - 0.5 * w) * ratiow + 0.5;
							int top = (int)(y - 0.5 * h) * ratioh + 0.5;
							classIds.push_back(classIdPoint.x);
							confidences.push_back(max_class_socre * obj_conf);
							boxes.push_back(cv::Rect(left, top, int(w * ratiow), int(h * ratioh)));
						}
					}
					pdata += net_width;
				}
			}
		}
	}
	vector<int> nms_result;
	cv::dnn::NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold, nms_result);
	for (size_t i = 0; i < nms_result.size(); i++)
	{
		int idx = nms_result[i];
		Output result;
		result.id = classIds[idx];
		result.confidence = confidences[idx];
		result.box = boxes[idx];
		output.push_back(result);
	}
	/*imshow("image", image);
	waitKey(0);*/
}

void YOLO::drawPred(cv::Mat& img, vector<Output> result, vector<cv::Scalar> color)   // Draw the predicted bounding box
{
	for (int i = 0; i < result.size(); i++) {
		int left, top;
		left = result[i].box.x;
		top = result[i].box.y;
		int color_num = i;
		rectangle(img, result[i].box, color[result[i].id], 2, 2);
		string label = cv::format("%.2f", result[i].confidence);
		label = class_names[result[i].id] + ":" + label;

		int baseLine;
		cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
		top = cv::max(top, labelSize.height);
		//rectangle(frame, Point(left, top - int(1.5 * labelSize.height)), Point(left + int(1.5 * labelSize.width), top + baseLine), Scalar(0, 255, 0), FILLED);
		putText(img, label, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX, 1, color[result[i].id], 2);
	}
	/*imshow("imageshow", img);
	cv::waitKey();*/
}
