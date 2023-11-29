#include "qtyolowindow2.h"
using namespace cv;
bool caiji_flag = 0;
bool detect_flag = 0;
bool save_flag = 0;
extern std::mutex mtx;
//构造函数
QTyoloWindow::QTyoloWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);//界面初始化
	//链接清空按钮，清空状态栏
	connect(ui.clear_state_btn, SIGNAL(clicked()), this, SLOT(bp_clearMessage_clicked()));
	//打开相机 关闭相机 开始采集 结束采集
	connect(ui.open_btn, SIGNAL(clicked()), this, SLOT(bp_openCam_clicked()));
	connect(ui.close_btn, SIGNAL(clicked()), this, SLOT(bp_closeCam_clicked()));
	connect(ui.start_btn, SIGNAL(clicked()), this, SLOT(bp_startAcq_clicked()));
	connect(ui.end_btn, SIGNAL(clicked()), this, SLOT(bp_stopAcq_clicked()));
	//开始检测 结束检测
	connect(ui.start_dec_btn, SIGNAL(clicked()), this, SLOT(bp_startDet_clicked()));
	connect(ui.end_dec_btn, SIGNAL(clicked()), this, SLOT(bp_stopDet_clicked()));
	//保存图片 结束保存
	connect(ui.start_save_btn, SIGNAL(clicked()), this, SLOT(bp_startsaveimg_clicked()));
	connect(ui.end_save_btn, SIGNAL(clicked()), this, SLOT(bp_stopsaveimg_clicked()));
	//打开图片 检测单张
	connect(ui.open_image_btn, SIGNAL(clicked()), this, SLOT(bp_openimg_clicked()));
	connect(ui.start_dec_btn_image, SIGNAL(clicked()), this, SLOT(bp_detoneimg_clicked()));
	//测试代码
	ui.textBrowser->append("welcome93");
	cv::Mat img0 = cv::imread("C:/Users/DELL/Desktop/1.jpg");
	cv::cvtColor(img0, img0, COLOR_BGR2RGB);
	QImage Qtemp = QImage((const unsigned char*)(img0.data), img0.cols, img0.rows, img0.step, QImage::Format_RGB888);
	ui.label->setPixmap(QPixmap::fromImage(Qtemp));
	ui.label->setScaledContents(1);

	cam = new DahengCamera();//实例化相机

	IsCamOpen_flag = 0;//相机成功打开标志位 未打开0 打开1
	IsCamAcq_flag = 0;//相机采集标志位 未采集0 采集1
	IsDetect_flag = 0;//检测标志位 未检测0，检测1
	IsSaveimg_flag = 0;//保存图片标志位 未保存0，保存1
	IsDetoneimg_flg = 0;//检测单张图片标志位 未检测0，检测1

	//创建定时器 刷新图片
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
	timer->setInterval(48); // 设置定时器间隔为0.48秒

	//创建一个线程用于检测与刷新
	//img_thread = new ImageThread();
	//connect(img_thread, &ImageThread::detectSignal, this, &QTyoloWindow::refreshimage);
}
QTyoloWindow::~QTyoloWindow()
{
	delete cam;//释放堆上的内存
	delete timer;
}
//清空状态栏槽函数
void QTyoloWindow::bp_clearMessage_clicked()
{
	ui.textBrowser->clear();
}
//打开相机
void QTyoloWindow::bp_openCam_clicked()
{
	cam->openCam_fuc();
	if (cam->IsHaveCam_flg == 0)
	{
		QMessageBox::critical(nullptr, "Error", "Camera not found!");
		return;
	}
	else if (cam->IsHaveLiu_flg == 0)
	{
		QMessageBox::critical(nullptr, "Error", "No video stream!");
		return;
	}
	else if ((cam->IsHaveCam_flg == 1) && (cam->IsHaveLiu_flg == 1))
	{
		QMessageBox::information(nullptr, "imformation", "Camera successfully opened");
		IsCamOpen_flag = 1;
	}
}
//关闭相机
void QTyoloWindow::bp_closeCam_clicked()
{
	if ((IsCamOpen_flag == 1) && (IsCamAcq_flag == 0))//只有相机打开并且结束采集才能关闭相机
	{
		cam->closeCam_fuc();
		IsCamOpen_flag = 0;//相机关闭，标志位置0
	}
	else
		QMessageBox::critical(nullptr, "Error", "Camera is not opened!");
}
//开始采集
void QTyoloWindow::bp_startAcq_clicked()
{
	if (IsCamOpen_flag == 1)//如果相机打开了才能采集
	{
		cam->StartAcquisition();
		IsCamAcq_flag = 1;//开始采集
		caiji_flag = 1;
		timer->start();//开启定时器

		//创建一个线程用于检测与刷新  线程启动
		//img_thread->start();
	}
	else
		QMessageBox::critical(nullptr, "Error", "Camera is not opened!");
}
//结束采集
void QTyoloWindow::bp_stopAcq_clicked()
{
	if (IsCamAcq_flag == 1)//相机采集后才能结束采集
	{
		cam->StopAcquisition();
		IsCamAcq_flag = 0;//相机不再采集，标志位置0
		caiji_flag = 0;
		//delete img_thread;
	}
	else
		QMessageBox::critical(nullptr, "Error", "Camera not capturing!");
}
//定时器刷新界面
void QTyoloWindow::timerTimeout()
{
	if (!rgb_img.empty())//如果对象不为空
	{	
		mtx.lock();
		cv::Mat image_ = rgb_img.clone();
		mtx.unlock();
		//刷新采集到的图
		if ((IsCamAcq_flag == 1) && (IsDetect_flag == 0))//开始采集且没有检测
		{
			if (IsSaveimg_flag == 1)//如果保存图片
			{
				cv::imshow("text", image_);
			}
			//将相机采集的图片每隔一段时间刷新在label上
			cv::cvtColor(image_, image_, COLOR_BGR2RGB);
			QImage Qtemp = QImage((const unsigned char*)(image_.data), image_.cols, image_.rows, image_.step, QImage::Format_RGB888);
			ui.label->setPixmap(QPixmap::fromImage(Qtemp));
			ui.label->setScaledContents(1);
		}
		//刷新检测的图
		else if ((IsCamAcq_flag == 1) && (IsDetect_flag == 1))
		{
			cv::Mat img1 = cv::imread("C:/Users/tianmingYun/Desktop/2.PNG");
			cv::cvtColor(img1, img1, COLOR_BGR2RGB);
			QImage Qtemp = QImage((const unsigned char*)(img1.data), img1.cols, img1.rows, img1.step, QImage::Format_RGB888);
			ui.label->setPixmap(QPixmap::fromImage(Qtemp));
			ui.label->setScaledContents(1);
		}
	}
}
void QTyoloWindow::bp_startDet_clicked()
{
	if (IsCamAcq_flag == 1)
	{
		IsDetect_flag = 1;//开始检测标志位置1
		detect_flag = 1;
	}
	else
	{
		QMessageBox::critical(nullptr, "Error", "Camera not capturing!");
	}
}
void QTyoloWindow::bp_stopDet_clicked()
{
	if ((IsCamAcq_flag == 1) && (IsDetect_flag == 1))
	{
		IsDetect_flag = 0;//开始检测标志位置0,结束检测
		detect_flag = 0;
	}
	else
	{
		QMessageBox::critical(nullptr, "Error", "Camera not capturing or detecing!");
	}
}
void QTyoloWindow::bp_startsaveimg_clicked()
{
	if ((IsCamAcq_flag == 1) && (IsDetect_flag == 0))
	{
		IsSaveimg_flag = 1;
		save_flag = 1;
	}
}
void QTyoloWindow::bp_stopsaveimg_clicked()
{
	if ((IsCamAcq_flag == 1) && (IsDetect_flag == 0) && (IsDetect_flag == 1))
	{
		IsSaveimg_flag = 0;
		save_flag = 0;
	}
}
void QTyoloWindow::bp_openimg_clicked()
{
	// 打开本地文件对话框并选择一个文件
	QString fileName = QFileDialog::getOpenFileName(nullptr, "choose a file", "", "all files (*.*)");
	// 如果用户选择了文件
	if (!fileName.isEmpty())
	{
		filePathStr = fileName.toStdString();
		cv::Mat img2 = cv::imread(filePathStr);
		if (!img2.empty())
		{
			QString str = "The fielpath is %1";
			QString result = str.arg(fileName);
			ui.textBrowser_image->append(result);//路径显示到状态栏

			cv::cvtColor(img2, img2, COLOR_BGR2RGB);
			QImage Qtemp = QImage((const unsigned char*)(img2.data), img2.cols, img2.rows, img2.step, QImage::Format_RGB888);
			ui.label_image->setPixmap(QPixmap::fromImage(Qtemp));
			ui.label_image->setScaledContents(1);
			IsDetoneimg_flg = 1;//可以检测单张了
		}
		else
		{
			QMessageBox::critical(nullptr, "Error", "please open a picture!");
		}
	}
	else
	{
		QMessageBox::critical(nullptr, "Error", "no file!");
	}
}
void QTyoloWindow::bp_detoneimg_clicked()
{
	if (IsDetoneimg_flg == 1)
	{
		cv::Mat img2 = cv::imread(filePathStr);
		QImage Qtemp = QImage((const unsigned char*)(img2.data), img2.cols, img2.rows, img2.step, QImage::Format_RGB888);
		ui.label_image_2->setPixmap(QPixmap::fromImage(Qtemp));
		ui.label_image_2->setScaledContents(1);
		IsDetoneimg_flg = 0;
	}
}

//检测 刷新 线程用的函数
void ImageThread::run()
{
	QImage Qtemp_image_;
	while (caiji_flag)
	{	
		if (!rgb_img.empty())//如果对象不为空
		{
			mtx.lock();
			cv::Mat image_ = rgb_img;
			mtx.unlock();
			//刷新采集到的图
			if ((caiji_flag == 1) && (detect_flag == 0))//开始采集且没有检测
			{
				if (save_flag == 1)//如果保存图片
				{
					cv::imshow("text", image_);
				}
				cv::cvtColor(image_, image_, COLOR_BGR2RGB);
			}
			//刷新检测的图
			else if ((caiji_flag == 1) && (detect_flag == 1))
			{
				//检测代码
			}
			Qtemp_image_ = QImage(image_.data, image_.cols, image_.rows, image_.step, QImage::Format_RGB888).copy();
			std::this_thread::sleep_for(1ms);
			emit detectSignal(Qtemp_image_);
		}
	}
}
void QTyoloWindow::refreshimage(const QImage& Qtemp_image_)
{
	ui.textBrowser->append("welcome93");
	//QImage Qtemp = QImage((const unsigned char*)(image_.data), image_.cols, image_.rows, image_.step, QImage::Format_RGB888);
	ui.label->setPixmap(QPixmap::fromImage(Qtemp_image_));
	ui.label->setScaledContents(1);
}
