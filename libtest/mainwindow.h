#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "requestlib.h"
#include "y_algorithm.h"
#include "getprice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void GetMsgFinish(QString msg);

    void GetContractMsgFinish(Contract_info info);

    void GetTotalHoldingsFinish(Total_Holdings info);

    void GetPostOrderInfoFinish(Post_Order_Info info);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void GetBtcPricefinish(QString price);

    void GetETHPricefinish(QString price);

    void Getpingfinish(QByteArray bytes);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void Err(QString err);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    RequestLib m_RequestTest;
    GetPrice *m_ps;
    QString accees_key;
    QString secret_key;
};

#endif // MAINWINDOW_H
