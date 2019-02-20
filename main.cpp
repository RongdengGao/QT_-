#include "mainwindow.h"
#include <QApplication>
#include <carouselimagewindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*-2019.2.18 andy*////测试进度条显示
    MainWindow w;
    w.show();
    //-end

    /*2019.2.18 andy*////测试图片轮播
    CarouselImageWindow w2;
    w2.addImage("D:/Qt_Program/QT_slider/test1.jpg");
    w2.addImage("D:/Qt_Program/QT_slider/test2.jpg");
    w2.addImage("D:/Qt_Program/QT_slider/test3.jpg");
    w2.addImage("D:/Qt_Program/QT_slider/test4.jpg");
    w2.startPlay();
    w2.show();
    //-end

    return a.exec();
}
