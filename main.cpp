#include "qtyolowindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTyoloWindow w;
    w.show();
    return a.exec();
}
