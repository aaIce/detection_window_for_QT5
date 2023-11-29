#include "myDahengCamera.h"
cv::Mat rgb_img(100, 100, CV_8UC3); 
std::mutex mtx;//互斥锁
bool once_rgbimg = 0;  //rgb_img重新分配内存标志位 只进行一次

DahengCamera::DahengCamera()
{
	IsHaveCam_flg = 0;
	IsHaveLiu_flg = 0;
	AcqTreadStop_flg = 0;
	//初始化设备
	IGXFactory::GetInstance().Init();
}
DahengCamera::~DahengCamera()
{

}
void DahengCamera::openCam_fuc()//打开相机函数
{
	GxIAPICPP::gxdeviceinfo_vector vectorDeviceInfo;
	IGXFactory::GetInstance().UpdateDeviceList(1000, vectorDeviceInfo);//枚举设备
	for (uint32_t i = 0; i < vectorDeviceInfo.size(); i++)//打印设备信息
	{
		cout << vectorDeviceInfo[i].GetVendorName() << endl;
		cout << vectorDeviceInfo[i].GetModelName() << endl;
	}
	if (vectorDeviceInfo.size() == 0)//判断设备是否为空
	{
		IsHaveCam_flg = 0;//没有相机
		cout << "没有相机" << endl;
		return;
	}
	else
		IsHaveCam_flg = 1;//有相机
	//打开设备
	m_ObjDevicePtr = IGXFactory::GetInstance().OpenDeviceBySN(vectorDeviceInfo[0].GetSN(), GX_ACCESS_EXCLUSIVE);//打开设备
	//判断设备流是否大于零，如果大于零则打开流
	int nStreamCount = m_ObjDevicePtr->GetStreamCount();
	if (nStreamCount)
	{
		IsHaveLiu_flg = 1;
		m_ObjStreamPtr = m_ObjDevicePtr->OpenStream(0);
	}
	else
	{
		IsHaveLiu_flg = 0;//没有流
		cout << "没有流" << endl;
		return;
	}
}
void DahengCamera::closeCam_fuc()
{
	//关闭流对象
	m_ObjStreamPtr->Close();
	IGXFactory::GetInstance().Uninit();
}
void DahengCamera::StartAcquisition()//开始采集函数
{
	pCaptureEventHandler = new CSampleCaptureEventHandler();//用于回调函数
	//注册回调函数
	//m_ObjStreamPtr->RegisterCaptureCallback(pCaptureEventHandler, NULL);
	//开启流层通道
	//m_ObjStreamPtr->StartGrab();
	//获取远端设备属性控制器
	//m_ObjFeatureControlPtr = m_ObjDevicePtr->GetRemoteFeatureControl();
	//给设备发送采集命令
	//m_ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
	
	//开启线程 来进行采集
	thread AcqTread_(&DahengCamera::thread_fuc,this);
	AcqTread_.detach();//守护线程，子线程与主线程分离 防止线程销毁后报错
	//开启流层通道
	m_ObjStreamPtr->StartGrab();
}
void DahengCamera::StopAcquisition()//停止采集函数
{
	AcqTreadStop_flg = 1;
	//发送停采命令
	m_ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
	//关闭流层采集
	m_ObjStreamPtr->StopGrab();
	//注销采集回调
	m_ObjStreamPtr->UnregisterCaptureCallback();
	delete pCaptureEventHandler;
	pCaptureEventHandler = NULL;
}
void DahengCamera::thread_fuc()
{
	//注册回调函数
	m_ObjStreamPtr->RegisterCaptureCallback(pCaptureEventHandler, NULL);
	//获取远端设备属性控制器
	m_ObjFeatureControlPtr = m_ObjDevicePtr->GetRemoteFeatureControl();
	//给设备发送采集命令
	m_ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
	while (AcqTreadStop_flg == 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
void DahengCamera::CSampleCaptureEventHandler::DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam)
{
	if (objImageDataPointer->GetStatus() == GX_FRAME_STATUS_SUCCESS)
	{	
		//uint64_t nWidth = objImageDataPointer->GetWidth();
		//uint64_t nHeight = objImageDataPointer->GetHeight();

		//cv::Mat img(objImageDataPointer->GetHeight(), objImageDataPointer->GetWidth(), CV_8UC3);
		//memcpy(img.data, objImageDataPointer->ConvertToRGB24(GX_BIT_0_7, GX_RAW2RGB_NEIGHBOUR, true), (objImageDataPointer->GetHeight())*(objImageDataPointer->GetWidth()) * 3);
		//cv::flip(img, img, 0);
		mtx.lock();
		if (once_rgbimg == 0)
		{
			rgb_img.create(objImageDataPointer->GetHeight(), objImageDataPointer->GetWidth(), CV_8UC3);
			once_rgbimg = 1;
		}
		memcpy(rgb_img.data, objImageDataPointer->ConvertToRGB24(GX_BIT_0_7, GX_RAW2RGB_NEIGHBOUR, true), (objImageDataPointer->GetHeight())*(objImageDataPointer->GetWidth()) * 3);
		cv::flip(rgb_img, rgb_img, 0);
		mtx.unlock();
		this_thread::sleep_for(1ms);
		//mtx.lock();
		//重新给rgb_img分配空间，分配的和拍摄到的一样
		//rgb_img.create(objImageDataPointer->GetHeight(), objImageDataPointer->GetWidth(), CV_8UC3);
		//rgb_img = img.clone();//把得到的img给全局变量rgb_img
		//mtx.unlock();
		//this_thread::sleep_for(1ms);
		
	}
}
