#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_qtyolowindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "myDahengCamera.h"
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QThread>

extern bool caiji_flag;
extern bool detect_flag;
extern bool save_flag;

class ImageThread : public QThread
{
	Q_OBJECT
public:
	ImageThread(){}
signals:
	void detectSignal(const QImage& Qtemp_image_);
protected:
	void run() override;
};

class QTyoloWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTyoloWindow(QWidget *parent = nullptr);
    ~QTyoloWindow();

	bool IsCamOpen_flag;//相机是否打开标志位
	bool IsCamAcq_flag;//相机是否采集标志位
	bool IsDetect_flag;//是否开始检测标志位
	bool IsSaveimg_flag;//是否开始保存标志位
	bool IsDetoneimg_flg;//是否检测单张标志位
	std::string filePathStr;//用于接收打开的图片路径
	DahengCamera* cam;
	ImageThread* img_thread;
	//QTimer* timer;

private:
	Ui::QTyoloWindowClass ui;
// 自定义的槽函数
private slots:
	void bp_clearMessage_clicked();//清空消息
	void bp_openCam_clicked();//打开相机
	void bp_closeCam_clicked();//关闭相机
	void bp_startAcq_clicked();//开始采集
	void bp_stopAcq_clicked();//结束采集
	void timerTimeout();
	void refreshimage(const QImage& Qtemp_image_);
	void bp_startDet_clicked();//开始检测
	void bp_stopDet_clicked();//结束检测
	void bp_startsaveimg_clicked();//开始保存
	void bp_stopsaveimg_clicked();//结束保存
	void bp_openimg_clicked();//打开图片
	void bp_detoneimg_clicked();//检测单张
};


