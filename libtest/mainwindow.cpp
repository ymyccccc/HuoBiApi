#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    accees_key = "rfhfg2mkl3-d4eef901-8d652141-c8e43";
    secret_key = "5d6ea641-448eed43-50979250-f324d";
    m_ps = new GetPrice();
    m_ps->ConnectToServer();
    y_Algorithm::initData();
    m_RequestTest.SetKey(accees_key, secret_key);

    connect(m_ps, SIGNAL(GetBtcPricefinish(QString)), this, SLOT(GetBtcPricefinish(QString)));
    connect(m_ps, SIGNAL(GetETHPricefinish(QString)), this, SLOT(GetETHPricefinish(QString)));
    connect(m_ps, SIGNAL(Getping(QByteArray)), this, SLOT(Getpingfinish(QByteArray)));
    connect(&m_RequestTest, SIGNAL(GetMsgFinish(QString)), this, SLOT(GetMsgFinish(QString)));
    connect(&m_RequestTest, SIGNAL(GetContractMsgFinish(Contract_info)), this, SLOT(GetContractMsgFinish(Contract_info)));
    connect(&m_RequestTest, SIGNAL(GetTotalHoldingsFinish(Total_Holdings)), this, SLOT(GetTotalHoldingsFinish(Total_Holdings)));
    connect(&m_RequestTest, SIGNAL(GetPostOrderInfoFinish(Post_Order_Info)), this, SLOT(GetPostOrderInfoFinish(Post_Order_Info)));
    connect(&m_RequestTest, SIGNAL(Err(QString)), this, SLOT(Err(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    m_RequestTest.GetMsg(str);
    ui->textEdit->clear();

}

void MainWindow::GetMsgFinish(QString msg)
{
    ui->textEdit->append(msg);
}

void MainWindow::GetContractMsgFinish(Contract_info info)
{
    ui->textEdit->clear();
    ui->textEdit->append(info.contract_code);
}

void MainWindow::GetTotalHoldingsFinish(Total_Holdings info)
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::number(info.volume));
}

void MainWindow::GetPostOrderInfoFinish(Post_Order_Info info)
{
    ui->textEdit->clear();
    ui->textEdit->append("send order succ!");
    ui->textEdit->append(QString("订单id：") + info.order_id_str);
    ui->textEdit->append(QString("自填订单id：") + info.client_order_id);

}

void MainWindow::on_pushButton_2_clicked()
{
    m_RequestTest.GetContractMsg(y_BTC, y_This_week);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->comboBox->currentText() == "BTC") {
        m_ps->SubscriptionPrice(y_BTC, y_This_week);
    } else if (ui->comboBox->currentText() == "ETH") {
        m_ps->SubscriptionPrice(y_ETH, y_This_week);
    }
}

void MainWindow::GetBtcPricefinish(QString price)
{
    qDebug() << "int slot MainWindow::GetBtcPricefinish";
    QString str("BTC price is:");
    str += price;
    ui->textEdit->append(str);
}

void MainWindow::GetETHPricefinish(QString price)
{
    qDebug() << "int slot MainWindow::GetETHPricefinish";
    QString str("ETH price is:");
    str += price;
    ui->textEdit->append(str);
}

void MainWindow::Getpingfinish(QByteArray bytes)
{
    ui->textEdit->append(QString(bytes));
}

void MainWindow::on_pushButton_4_clicked()
{
    m_ps->SetWebsocketUrl(ui->lineEdit_url->text());
    m_ps->ConnectToServer();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString str = ui->lineEdit_4->text();
    qDebug()<< str.toUtf8().toHex();

    QByteArray a("2434002665436");
    QString t(a);
    qDebug()<< "a= " << a;

    //qDebug()<< "stringToHexString:" << stringToHexString(a);
}

QString stringToHexString(QString strMsg)
{
    QString strResult;

    QByteArray arry = strMsg.toUtf8();

    for (int i = 0; i < arry.size(); ++i) {
        strResult += "0x";

        int arrHex[2];
        arrHex[0] = arry[i]/16;
        arrHex[1] = arry[i]%16;

        for(int j = 0; j < (int)(sizeof(arrHex)/sizeof(int)); j++){
            char ch = arrHex[j];
            if ((ch >= 0) && (ch <= 9))
                strResult.append(ch + '0');
            else
                strResult.append(ch + 55);
        }

        strResult += " ";
    }

    return strResult;
}


void MainWindow::on_pushButton_6_clicked()
{
    disconnect(m_ps, SIGNAL(Getping(QByteArray)), this, SLOT(Getpingfinish(QByteArray)));
}

void MainWindow::on_pushButton_7_clicked()
{
    m_RequestTest.GetContractMsg(y_BTC, y_This_week);
}

void MainWindow::on_pushButton_8_clicked()
{
    m_RequestTest.GetTotalHoldings(y_BTC, y_This_week);
}

void MainWindow::on_pushButton_9_clicked()
{
    m_RequestTest.GetMyAccountMsg(y_BTC);
}

void MainWindow::on_pushButton_10_clicked()
{
    m_RequestTest.GetMyHoldings(y_BTC);
}

void MainWindow::on_pushButton_11_clicked()
{
    Contract_Order_Msg ordermsg;
    ordermsg.Symboltype = y_BTC;
    ordermsg.type       = y_This_week;
    ordermsg.tradetype  = Open_To_Buy_More;
    ordermsg.client_order_id = "1111";
    ordermsg.price      = "30000";
    ordermsg.volume     = 1;
    ordermsg.lever_rate = 20;
    ordermsg.order_price_type = "limit";

    m_RequestTest.ContractOrder(ordermsg);
}

void MainWindow::on_pushButton_12_clicked()
{
    Contract_Order_Msg ordermsg;
    ordermsg.Symboltype = y_BTC;
    ordermsg.type       = y_This_week;
    ordermsg.tradetype  = Close_To_Sell_More;
    ordermsg.client_order_id = "1111";
    ordermsg.price      = "30000";
    ordermsg.volume     = 1;
    ordermsg.lever_rate = 20;
    ordermsg.order_price_type = "limit";

    m_RequestTest.ContractOrder(ordermsg);
}

void MainWindow::Err(QString err)
{
    ui->textEdit->append(err);
}

void MainWindow::on_pushButton_13_clicked()
{
    m_RequestTest.SetKey(ui->lineEdit_url_2->text(), ui->lineEdit_url_3->text());
}

void MainWindow::on_pushButton_14_clicked()
{

    m_RequestTest.GetContractOrderInfo(y_BTC, QString(), 1111);
}
