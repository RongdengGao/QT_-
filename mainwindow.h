#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qroundprogressbar.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int mPresent;
    int m_nRotationAngle;
    QTimer* mTimer;
    QRoundProgressBar *mRoundBar;
private:
    Ui::MainWindow *ui;

private slots:
    void onTimeOut();
    void updatePaint();
};

#endif // MAINWINDOW_H
