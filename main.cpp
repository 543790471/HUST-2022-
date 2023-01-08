#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//定义应用界面
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//或者"GBK",不分大小写
//    QTextCodec::setCodecForLocale(codec);
    MainWindow w;//定义主窗口，打开
    w.show();
    return a.exec();
}
