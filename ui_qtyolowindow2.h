/********************************************************************************
** Form generated from reading UI file 'qtyolowindow2opWuUY.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTYOLOWINDOW2OPWUUY_H
#define QTYOLOWINDOW2OPWUUY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTyoloWindow2Class
{
public:
	QWidget *centralWidget;
	QFrame *frame;
	QTabWidget *tabWidget;
	QWidget *tab;
	QLabel *label;
	QTextBrowser *textBrowser;
	QLabel *label_state;
	QFrame *line_2;
	QFrame *line_3;
	QFrame *line_4;
	QTabWidget *tabWidget_2;
	QWidget *tab_3;
	QPushButton *end_dec_btn;
	QPushButton *close_btn;
	QPushButton *start_btn;
	QPushButton *start_dec_btn;
	QPushButton *open_btn;
	QPushButton *end_btn;
	QPushButton *clear_state_btn;
	QLabel *choose_weight;
	QPushButton *load_model_btn;
	QWidget *tab_4;
	QPushButton *end_save_btn;
	QPushButton *start_save_btn;
	QLabel *choose_imgpath;
	QPushButton *choose_path_btn;
	QFrame *line_10;
	QLabel *label2;
	QFrame *line;
	QFrame *line_11;
	QFrame *line_12;
	QFrame *line_13;
	QWidget *tab_2;
	QLabel *label_image;
	QFrame *line_6;
	QLabel *label_image_2;
	QPushButton *start_dec_btn_image;
	QPushButton *open_image_btn;
	QFrame *line_7;
	QLabel *label_state_image;
	QTextBrowser *textBrowser_image;
	QFrame *line_8;
	QFrame *line_9;
	QFrame *line_16;
	QLabel *choose_weight_2;
	QPushButton *load_model_btn_2;
	QLabel *label_title;
	QFrame *line_5;

	void setupUi(QMainWindow *QTyoloWindow2Class)
	{
		if (QTyoloWindow2Class->objectName().isEmpty())
			QTyoloWindow2Class->setObjectName(QString::fromUtf8("QTyoloWindow2Class"));
		QTyoloWindow2Class->resize(1212, 973);
		centralWidget = new QWidget(QTyoloWindow2Class);
		centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
		frame = new QFrame(centralWidget);
		frame->setObjectName(QString::fromUtf8("frame"));
		frame->setGeometry(QRect(0, 0, 1211, 971));
		frame->setStyleSheet(QString::fromUtf8(""));
		frame->setFrameShape(QFrame::StyledPanel);
		frame->setFrameShadow(QFrame::Raised);
		tabWidget = new QTabWidget(frame);
		tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
		tabWidget->setGeometry(QRect(20, 60, 1181, 901));
		tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
			"\n"
			"min-width:120px;\n"
			"\n"
			"min-height:30px;\n"
			"\n"
			"color:rgb(0,0,0);\n"
			"\n"
			"font:12px \"Microsoft YaHei\";\n"
			"\n"
			"border: 0px solid;\n"
			"\n"
			"\n"
			"\n"
			"}\n"
			"\n"
			"QTabBar::tab:selected{\n"
			"\n"
			"min-width:120px;\n"
			"\n"
			"min-height:30px;\n"
			"color:rgb(0,0,0);\n"
			"\n"
			"font:18px \"Microsoft YaHei\";\n"
			"\n"
			"border: 0px solid;\n"
			"\n"
			"border-bottom: 2px solid;\n"
			"\n"
			"border-color: #4796f0;\n"
			"\n"
			"}"));
		tab = new QWidget();
		tab->setObjectName(QString::fromUtf8("tab"));
		label = new QLabel(tab);
		label->setObjectName(QString::fromUtf8("label"));
		label->setGeometry(QRect(20, 80, 701, 600));
		label->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		textBrowser = new QTextBrowser(tab);
		textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
		textBrowser->setGeometry(QRect(760, 310, 411, 551));
		QFont font;
		font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font.setPointSize(12);
		font.setBold(true);
		font.setWeight(75);
		textBrowser->setFont(font);
		textBrowser->setStyleSheet(QString::fromUtf8("font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"color:black;\n"
			"background-color: rgba(49,54,98,0.0);\n"
			"border-width:0;\n"
			"border-style:outset;\n"
			"border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		label_state = new QLabel(tab);
		label_state->setObjectName(QString::fromUtf8("label_state"));
		label_state->setGeometry(QRect(770, 280, 121, 31));
		QFont font1;
		font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font1.setPointSize(14);
		font1.setBold(true);
		font1.setWeight(75);
		label_state->setFont(font1);
		label_state->setStyleSheet(QString::fromUtf8("#label_state {	\n"
			"	color:rgb(157,191,250);\n"
			"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"}"));
		line_2 = new QFrame(tab);
		line_2->setObjectName(QString::fromUtf8("line_2"));
		line_2->setGeometry(QRect(900, 290, 271, 20));
		line_2->setFrameShape(QFrame::HLine);
		line_2->setFrameShadow(QFrame::Sunken);
		line_3 = new QFrame(tab);
		line_3->setObjectName(QString::fromUtf8("line_3"));
		line_3->setGeometry(QRect(750, 290, 21, 20));
		line_3->setFrameShape(QFrame::HLine);
		line_3->setFrameShadow(QFrame::Sunken);
		line_4 = new QFrame(tab);
		line_4->setObjectName(QString::fromUtf8("line_4"));
		line_4->setGeometry(QRect(740, 300, 21, 561));
		line_4->setFrameShape(QFrame::VLine);
		line_4->setFrameShadow(QFrame::Sunken);
		tabWidget_2 = new QTabWidget(tab);
		tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
		tabWidget_2->setGeometry(QRect(760, 10, 421, 261));
		tab_3 = new QWidget();
		tab_3->setObjectName(QString::fromUtf8("tab_3"));
		end_dec_btn = new QPushButton(tab_3);
		end_dec_btn->setObjectName(QString::fromUtf8("end_dec_btn"));
		end_dec_btn->setGeometry(QRect(310, 126, 101, 41));
		end_dec_btn->setFont(font);
		end_dec_btn->setStyleSheet(QString::fromUtf8("\n"
			"\n"
			"#end_dec_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		close_btn = new QPushButton(tab_3);
		close_btn->setObjectName(QString::fromUtf8("close_btn"));
		close_btn->setGeometry(QRect(30, 126, 101, 41));
		close_btn->setFont(font);
		close_btn->setStyleSheet(QString::fromUtf8("\n"
			"#close_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		start_btn = new QPushButton(tab_3);
		start_btn->setObjectName(QString::fromUtf8("start_btn"));
		start_btn->setGeometry(QRect(170, 66, 101, 41));
		start_btn->setFont(font);
		start_btn->setStyleSheet(QString::fromUtf8("#start_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}\n"
			""));
		start_dec_btn = new QPushButton(tab_3);
		start_dec_btn->setObjectName(QString::fromUtf8("start_dec_btn"));
		start_dec_btn->setGeometry(QRect(310, 66, 101, 41));
		start_dec_btn->setFont(font);
		start_dec_btn->setStyleSheet(QString::fromUtf8("#start_dec_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}\n"
			"\n"
			""));
		open_btn = new QPushButton(tab_3);
		open_btn->setObjectName(QString::fromUtf8("open_btn"));
		open_btn->setGeometry(QRect(30, 66, 101, 41));
		open_btn->setFont(font);
		open_btn->setStyleSheet(QString::fromUtf8("#open_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		end_btn = new QPushButton(tab_3);
		end_btn->setObjectName(QString::fromUtf8("end_btn"));
		end_btn->setGeometry(QRect(170, 126, 101, 41));
		end_btn->setFont(font);
		end_btn->setStyleSheet(QString::fromUtf8("\n"
			"\n"
			"#end_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		clear_state_btn = new QPushButton(tab_3);
		clear_state_btn->setObjectName(QString::fromUtf8("clear_state_btn"));
		clear_state_btn->setGeometry(QRect(310, 180, 101, 41));
		clear_state_btn->setFont(font);
		clear_state_btn->setStyleSheet(QString::fromUtf8("\n"
			"\n"
			"#clear_state_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		choose_weight = new QLabel(tab_3);
		choose_weight->setObjectName(QString::fromUtf8("choose_weight"));
		choose_weight->setGeometry(QRect(40, 10, 351, 21));
		QFont font2;
		font2.setFamily(QString::fromUtf8("Times New Roman"));
		font2.setPointSize(10);
		choose_weight->setFont(font2);
		choose_weight->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		load_model_btn = new QPushButton(tab_3);
		load_model_btn->setObjectName(QString::fromUtf8("load_model_btn"));
		load_model_btn->setGeometry(QRect(320, 40, 75, 23));
		load_model_btn->setStyleSheet(QString::fromUtf8("#load_model_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		tabWidget_2->addTab(tab_3, QString());
		tab_4 = new QWidget();
		tab_4->setObjectName(QString::fromUtf8("tab_4"));
		end_save_btn = new QPushButton(tab_4);
		end_save_btn->setObjectName(QString::fromUtf8("end_save_btn"));
		end_save_btn->setGeometry(QRect(30, 126, 101, 41));
		end_save_btn->setFont(font);
		end_save_btn->setStyleSheet(QString::fromUtf8("\n"
			"\n"
			"#end_save_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		start_save_btn = new QPushButton(tab_4);
		start_save_btn->setObjectName(QString::fromUtf8("start_save_btn"));
		start_save_btn->setGeometry(QRect(30, 66, 101, 41));
		start_save_btn->setFont(font);
		start_save_btn->setStyleSheet(QString::fromUtf8("\n"
			"#start_save_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		choose_imgpath = new QLabel(tab_4);
		choose_imgpath->setObjectName(QString::fromUtf8("choose_imgpath"));
		choose_imgpath->setGeometry(QRect(30, 20, 351, 21));
		choose_imgpath->setFont(font2);
		choose_imgpath->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		choose_path_btn = new QPushButton(tab_4);
		choose_path_btn->setObjectName(QString::fromUtf8("choose_path_btn"));
		choose_path_btn->setGeometry(QRect(310, 50, 75, 23));
		choose_path_btn->setStyleSheet(QString::fromUtf8("#choose_path_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		tabWidget_2->addTab(tab_4, QString());
		line_10 = new QFrame(tab);
		line_10->setObjectName(QString::fromUtf8("line_10"));
		line_10->setGeometry(QRect(740, 10, 20, 271));
		line_10->setFrameShape(QFrame::VLine);
		line_10->setFrameShadow(QFrame::Sunken);
		label2 = new QLabel(tab);
		label2->setObjectName(QString::fromUtf8("label2"));
		label2->setGeometry(QRect(40, 20, 131, 51));
		QFont font3;
		font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font3.setPointSize(20);
		font3.setBold(true);
		font3.setWeight(75);
		label2->setFont(font3);
		label2->setStyleSheet(QString::fromUtf8("#label2 {	\n"
			"	color:rgb(0,0,0);\n"
			"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"}"));
		line = new QFrame(tab);
		line->setObjectName(QString::fromUtf8("line"));
		line->setGeometry(QRect(200, 40, 531, 16));
		line->setFrameShape(QFrame::HLine);
		line->setFrameShadow(QFrame::Sunken);
		line_11 = new QFrame(tab);
		line_11->setObjectName(QString::fromUtf8("line_11"));
		line_11->setGeometry(QRect(10, 40, 31, 16));
		line_11->setFrameShape(QFrame::HLine);
		line_11->setFrameShadow(QFrame::Sunken);
		line_12 = new QFrame(tab);
		line_12->setObjectName(QString::fromUtf8("line_12"));
		line_12->setGeometry(QRect(0, 50, 20, 641));
		line_12->setFrameShape(QFrame::VLine);
		line_12->setFrameShadow(QFrame::Sunken);
		line_13 = new QFrame(tab);
		line_13->setObjectName(QString::fromUtf8("line_13"));
		line_13->setGeometry(QRect(750, 265, 421, 31));
		line_13->setFrameShape(QFrame::HLine);
		line_13->setFrameShadow(QFrame::Sunken);
		tabWidget->addTab(tab, QString());
		tab_2 = new QWidget();
		tab_2->setObjectName(QString::fromUtf8("tab_2"));
		label_image = new QLabel(tab_2);
		label_image->setObjectName(QString::fromUtf8("label_image"));
		label_image->setGeometry(QRect(20, 10, 701, 421));
		label_image->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		line_6 = new QFrame(tab_2);
		line_6->setObjectName(QString::fromUtf8("line_6"));
		line_6->setGeometry(QRect(10, 426, 721, 20));
		line_6->setFrameShape(QFrame::HLine);
		line_6->setFrameShadow(QFrame::Sunken);
		label_image_2 = new QLabel(tab_2);
		label_image_2->setObjectName(QString::fromUtf8("label_image_2"));
		label_image_2->setGeometry(QRect(20, 440, 701, 421));
		label_image_2->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		start_dec_btn_image = new QPushButton(tab_2);
		start_dec_btn_image->setObjectName(QString::fromUtf8("start_dec_btn_image"));
		start_dec_btn_image->setGeometry(QRect(910, 110, 101, 41));
		start_dec_btn_image->setFont(font);
		start_dec_btn_image->setStyleSheet(QString::fromUtf8("\n"
			"\n"
			"#start_dec_btn_image:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		open_image_btn = new QPushButton(tab_2);
		open_image_btn->setObjectName(QString::fromUtf8("open_image_btn"));
		open_image_btn->setGeometry(QRect(780, 110, 101, 41));
		open_image_btn->setFont(font);
		open_image_btn->setStyleSheet(QString::fromUtf8("\n"
			"#open_image_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		line_7 = new QFrame(tab_2);
		line_7->setObjectName(QString::fromUtf8("line_7"));
		line_7->setGeometry(QRect(750, 290, 21, 20));
		line_7->setFrameShape(QFrame::HLine);
		line_7->setFrameShadow(QFrame::Sunken);
		label_state_image = new QLabel(tab_2);
		label_state_image->setObjectName(QString::fromUtf8("label_state_image"));
		label_state_image->setGeometry(QRect(770, 280, 81, 31));
		label_state_image->setFont(font1);
		label_state_image->setStyleSheet(QString::fromUtf8("#label_state_image {	\n"
			"	color:rgb(157,191,250);\n"
			"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"}"));
		textBrowser_image = new QTextBrowser(tab_2);
		textBrowser_image->setObjectName(QString::fromUtf8("textBrowser_image"));
		textBrowser_image->setGeometry(QRect(760, 310, 411, 551));
		textBrowser_image->setFont(font);
		textBrowser_image->setStyleSheet(QString::fromUtf8("font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"color:white;\n"
			"background-color: rgba(49,54,98,0.0);\n"
			"border-width:0;\n"
			"border-style:outset;\n"
			"border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		line_8 = new QFrame(tab_2);
		line_8->setObjectName(QString::fromUtf8("line_8"));
		line_8->setGeometry(QRect(740, 300, 21, 561));
		line_8->setFrameShape(QFrame::VLine);
		line_8->setFrameShadow(QFrame::Sunken);
		line_9 = new QFrame(tab_2);
		line_9->setObjectName(QString::fromUtf8("line_9"));
		line_9->setGeometry(QRect(850, 290, 321, 20));
		line_9->setFrameShape(QFrame::HLine);
		line_9->setFrameShadow(QFrame::Sunken);
		line_16 = new QFrame(tab_2);
		line_16->setObjectName(QString::fromUtf8("line_16"));
		line_16->setGeometry(QRect(0, 10, 20, 851));
		line_16->setFrameShape(QFrame::VLine);
		line_16->setFrameShadow(QFrame::Sunken);
		choose_weight_2 = new QLabel(tab_2);
		choose_weight_2->setObjectName(QString::fromUtf8("choose_weight_2"));
		choose_weight_2->setGeometry(QRect(780, 30, 351, 21));
		choose_weight_2->setFont(font2);
		choose_weight_2->setStyleSheet(QString::fromUtf8("border-left: 2px solid rgb(140,171,234);\n"
			"border-right: 2px solid rgb(140,171,234);\n"
			"border-top: 2px solid rgb(140,171,234);\n"
			"border-bottom: 2px solid rgb(140,171,234);"));
		load_model_btn_2 = new QPushButton(tab_2);
		load_model_btn_2->setObjectName(QString::fromUtf8("load_model_btn_2"));
		load_model_btn_2->setGeometry(QRect(1060, 60, 75, 23));
		load_model_btn_2->setStyleSheet(QString::fromUtf8("#load_model_btn:pressed{\n"
			"	padding-top:5px;\n"
			"	padding-left:5px;\n"
			"}"));
		tabWidget->addTab(tab_2, QString());
		label_title = new QLabel(frame);
		label_title->setObjectName(QString::fromUtf8("label_title"));
		label_title->setGeometry(QRect(10, 0, 455, 51));
		label_title->setFont(font3);
		label_title->setStyleSheet(QString::fromUtf8("#label_title {	\n"
			"	color:rgb(0,0,0);\n"
			"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
			"}"));
		line_5 = new QFrame(frame);
		line_5->setObjectName(QString::fromUtf8("line_5"));
		line_5->setGeometry(QRect(0, 40, 721, 21));
		line_5->setFrameShape(QFrame::HLine);
		line_5->setFrameShadow(QFrame::Sunken);
		QTyoloWindow2Class->setCentralWidget(centralWidget);

		retranslateUi(QTyoloWindow2Class);

		tabWidget->setCurrentIndex(0);
		tabWidget_2->setCurrentIndex(0);


		QMetaObject::connectSlotsByName(QTyoloWindow2Class);
	} // setupUi

	void retranslateUi(QMainWindow *QTyoloWindow2Class)
	{
		QTyoloWindow2Class->setWindowTitle(QCoreApplication::translate("QTyoloWindow2Class", "QTyoloWindow2", nullptr));
		label->setText(QString());
		label_state->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
		end_dec_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\273\223\346\235\237\346\243\200\346\265\213", nullptr));
		close_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\205\263\351\227\255\347\233\270\346\234\272", nullptr));
		start_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
		start_dec_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
		open_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
		end_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\273\223\346\235\237\351\207\207\351\233\206", nullptr));
		clear_state_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\346\270\205\347\251\272\344\277\241\346\201\257", nullptr));
		choose_weight->setText(QString());
		load_model_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
		tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("QTyoloWindow2Class", "\347\233\256\346\240\207\346\243\200\346\265\213", nullptr));
		end_save_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\273\223\346\235\237\344\277\235\345\255\230", nullptr));
		start_save_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
		choose_imgpath->setText(QString());
		choose_path_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
		tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("QTyoloWindow2Class", "\345\233\276\345\203\217\351\207\207\351\233\206", nullptr));
		label2->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\256\236\346\227\266\347\224\273\351\235\242", nullptr));
		tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("QTyoloWindow2Class", "\345\256\236\346\227\266\350\257\206\345\210\253", nullptr));
		label_image->setText(QString());
		label_image_2->setText(QString());
		start_dec_btn_image->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
		open_image_btn->setText(QCoreApplication::translate("QTyoloWindow2Class", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
		label_state_image->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
		choose_weight_2->setText(QString());
		load_model_btn_2->setText(QCoreApplication::translate("QTyoloWindow2Class", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
		tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QTyoloWindow2Class", "\345\233\276\347\211\207\350\257\206\345\210\253", nullptr));
		label_title->setText(QCoreApplication::translate("QTyoloWindow2Class", "\347\233\256\346\240\207\346\243\200\346\265\213\345\271\263\345\217\260", nullptr));
	} // retranslateUi

};

namespace Ui {
	class QTyoloWindow2Class : public Ui_QTyoloWindow2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTYOLOWINDOW2OPWUUY_H
