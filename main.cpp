#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//����Ӧ�ý���
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//����"GBK",���ִ�Сд
//    QTextCodec::setCodecForLocale(codec);
    MainWindow w;//���������ڣ���
    w.show();
    return a.exec();
}
