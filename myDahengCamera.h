#pragma once
#include "GalaxyIncludes.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <thread>
using namespace std;
extern cv::Mat rgb_img;//声明一个全局变量 用于存放拍摄的图片

class DahengCamera
{
public:
	DahengCamera();
	~DahengCamera();
	class CSampleCaptureEventHandler : public ICaptureEventHandler
	{
	public:
		void DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam);
		//void DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam)
		//{
		//	if (objImageDataPointer->GetStatus() == GX_FRAME_STATUS_SUCCESS)
		//	{
		//		uint64_t nWidth = objImageDataPointer->GetWidth();
		//		uint64_t nHeight = objImageDataPointer->GetHeight();
		//		//GX_PIXEL_FORMAT_ENTRY emPixelFormat = objImageDataPointer->GetPixelFormat();
		//		cv::Mat img(objImageDataPointer->GetHeight(), objImageDataPointer->GetWidth(), CV_8UC3);
		//		memcpy(img.data, objImageDataPointer->ConvertToRGB24(GX_BIT_0_7, GX_RAW2RGB_NEIGHBOUR, true), (objImageDataPointer->GetHeight())*(objImageDataPointer->GetWidth()) * 3);
		//		cv::flip(img, img, 0);
		//		cv::imwrite("C:/Users/tianmingYun/Desktop/text0.jpg", img);
		//		//cv::imshow("text",img);
		//		//cv::waitKey(1);
		//		rgb_img = img.clone();//把得到的img给全局变量rgb_img
		//	}
		//}
	};
	//大恒相机API
	CGXFeatureControlPointer *m_pFeatureEventHandler;//远端设备事件回调对象
	CSampleCaptureEventHandler *pCaptureEventHandler;//采集回调对象
	CGXDevicePointer m_ObjDevicePtr;//设备句柄
	CGXStreamPointer m_ObjStreamPtr;//设备流
	CGXFeatureControlPointer m_ObjFeatureControlPtr;//属性控制器
	CGXFeatureControlPointer m_ObjStreamFeatureControlPtr;//流层控制器
	
	bool IsHaveCam_flg;// 是否检测到相机标志位 是1 否0
	bool IsHaveLiu_flg;// 是否检测到流标志位 是1 否0
	bool AcqTreadStop_flg;//线程用
	void openCam_fuc();//打开相机
	void closeCam_fuc();//关闭相机
	void StartAcquisition();//开始采集
	void thread_fuc();//线程负责注册回调函数
	void StopAcquisition();//结束采集
};
