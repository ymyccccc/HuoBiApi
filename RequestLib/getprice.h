#ifndef GETPRICE_H
#define GETPRICE_H

#include "requestlib_global.h"
#include <QWebSocket>
#include "date.h"
#include "Reqcmd.h"
#include <QQueue>
#include <QMap>
class REQUESTLIBSHARED_EXPORT GetPrice : public QObject
{
    Q_OBJECT
public:
    explicit GetPrice(QObject *parent = 0);
    void SetWebsocketUrl(const QString& str);
    void ConnectToServer();
    bool DisconnectUrl();

    /**
     * @brief SubscriptionPrice
     * @param symbolType
     * @param contractType
     * 订阅某币种行情深度数据（用来得到当前btc价格）
     */
    void SubscriptionPrice(Symbol_Type symbolType, Contract_Type contractType);

public slots:
    void onconnected();
    void closeConnection();
    void onTextMessageReceived(QString str);
    void onerror(QAbstractSocket::SocketError err);
    void OnbinaryMessageReceived(QByteArray str);

private:
    void SendMsg(QString str);

    QByteArray UnCompress(QByteArray src);

    QMap<QString, QQueue<QString>> m_DataQueue;
    QWebSocket m_webSocket;
    QString m_url;
    bool m_isconnect;

signals:
    void GetBtcPricefinish(QString price);
    void GetETHPricefinish(QString price);
    void Getping(QByteArray bytes);



};

#endif // GETPRICE_H
