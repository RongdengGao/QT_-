#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qroundprogressbar.h"
#include <QPainter>
#include <QProgressBar>
#include <QPalette>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //--进度条显示
    mRoundBar = new QRoundProgressBar(this);
    //设置位置大小
    mRoundBar->setGeometry(50,100,200,200);
    //设置进度条的样式
    mRoundBar->setBarStyle(QRoundProgressBar::StylePie);
    //设置进度条数字的范围
    mRoundBar->setRange(0,100);
    //设置笔刷
    QPalette palette;
    palette.setBrush(QPalette::Window,Qt::NoBrush);
    palette.setBrush(QPalette::AlternateBase,Qt::NoBrush);
    palette.setBrush(QPalette::Highlight,QBrush(QColor(0,140,255)));
    palette.setColor(QPalette::Text,QColor(0,0,0));
    mRoundBar->setPalette(palette);
    //设置当前的数值
    mTimer = new QTimer(this);
    //每隔1/5秒就进行一次数据刷新
    mTimer->setInterval(200);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    //设置初始的数值
    mPresent = 0;
    //启动定时器
    mTimer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeOut()
{
    ++mPresent;
    if(mPresent >= 100)
    {
        mPresent = 0;
    }
    mRoundBar->setValue(mPresent);
}

// 改变角度，进行旋转
void MainWindow::updatePaint()
{
    m_nRotationAngle++;
    if (m_nRotationAngle > 360)
        m_nRotationAngle = 0;
    update();
}

