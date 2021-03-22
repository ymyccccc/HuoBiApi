#include "getprice.h"
#include <QUrl>
#include <QStringList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <y_algorithm.h>
#include <QtZlib/zlib.h>

GetPrice::GetPrice(QObject *parent) : QObject(parent)
{
    connect(&m_webSocket, SIGNAL(connected()), this, SLOT(onconnected()));
    connect(&m_webSocket, SIGNAL(disconnected()), this, SLOT(closeConnection()));
    connect(&m_webSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
    connect(&m_webSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onerror(QAbstractSocket::SocketError)));
    connect(&m_webSocket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(OnbinaryMessageReceived(QByteArray)));
    m_url = "api.btcgateway.pro";
    m_isconnect = false;
}

void GetPrice::SetWebsocketUrl(const QString &str)
{
    if(str.isEmpty()) {
        qDebug() << "url is empty";
        return;
    }
    if(m_isconnect = true) {
        m_webSocket.disconnect();
        m_isconnect = false;
    }
    m_url = str;
}

void GetPrice::ConnectToServer()
{
    QString path = QString("wss://%1/%2").arg(m_url).arg(WEB_SOCK_SUBSCRIB_WS);
    //QString path = QString("wss://%1").arg(m_url);
    qDebug() << "IN GetPrice::ConnectToServer:" << path;
    QUrl url(path);
    m_webSocket.open(url);
}

bool GetPrice::DisconnectUrl()
{
    if(m_isconnect) {
        if(m_webSocket.disconnect()){
            m_isconnect = false;
            return true;
        } else {
            return false;
        }
    }
    return true;

}


void GetPrice::SubscriptionPrice(Symbol_Type symbolType, Contract_Type contractType)
{
    QJsonObject json;
    QString cmd(WEBSOCKET_GET_MARKET);
    QString symbol = y_Algorithm::MapSymbol_Type.value(symbolType) + y_Algorithm::MapContract_Type2.value(contractType);
    cmd.replace("$symbol", symbol);
    cmd.replace("$type", "step10");

    json.insert("sub", cmd);
    json.insert("id", "0");
    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    SendMsg(json_str);
}

void GetPrice::onconnected()
{
    m_isconnect = true;
    qDebug() << "websocket onconnected...";
}

void GetPrice::closeConnection()
{
    qDebug() << "closeConnection";
}

void GetPrice::onTextMessageReceived(QString str)
{
    qDebug() << "rcv str: \n" << str;
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 心跳包维持
        QJsonObject ob = document.object();
           if(ob.contains("ping")) {
               long ping = QString::number(ob.value("ping").toDouble(), 'f', 0).toLong();
               QJsonObject json;
               json.insert("pong", ping);
               QJsonDocument document;
               document.setObject(json);
               QByteArray byte_array = document.toJson(QJsonDocument::Compact);
               QString json_str(byte_array);
               m_webSocket.sendTextMessage(json_str);
           } else {
               // 对回复的信息进行解析
               QString channel = ob.value("ch").toString(); 
               qDebug() << channel;
               QJsonObject tick = ob.value("tick").toObject();
               QJsonArray bids = tick.value("bids").toArray();
               qDebug() << "bids.size = " << bids.size();
               QJsonArray lastBid = bids.at(bids.size() - 1).toArray();
               double price = lastBid.at(0).toDouble();
               //int count = lastBid.at(1).toInt();
               //QQueue<QString> temp = m_DataQueue.value(strList.at(1)).enqueue(price);
               if(channel.contains("BTC")) {
                   qDebug() << "BTC price is: " << price;
                   emit GetBtcPricefinish(QString::number(price, 'f', 2));
               } else if (channel.contains("ETH")) {
                   emit GetETHPricefinish(QString::number(price, 'f', 2));
               }

               //todo: 存入数据库
           }
    }
}

void GetPrice::onerror(QAbstractSocket::SocketError err)
{
    qDebug() << "err" << err;
}

void GetPrice::OnbinaryMessageReceived(QByteArray str)
{
    QByteArray temp = UnCompress(str);
    //qDebug()<< "get msg:" << temp;
    //emit Getping(temp);
    QString contend(temp);
    if(temp.contains("ping")) { //心跳消息  异常断开后的处理
        temp.replace("ping","pong");
        SendMsg(temp);
    } else  {
        onTextMessageReceived(contend);
    }

}

void GetPrice::SendMsg(QString str)
{
    //qDebug() << "send string:" << str;
    m_webSocket.sendTextMessage(str);
}

/**
 * @brief GetPrice::UnCompress
 * @param
 * @return G-zip解压传过来的字节流
 */
QByteArray GetPrice::UnCompress(QByteArray src)
{
    QByteArray outBuffer;
    z_stream strm;
    strm.zalloc = NULL;
    strm.zfree = NULL;
    strm.opaque = NULL;

    strm.avail_in = src.size();
    strm.next_in = (Bytef *)src.data();

    int err = -1;
    err = inflateInit2(&strm, MAX_WBITS + 16);
    if (err == Z_OK) {
        while (true)
        {
            char buffer[4096] = { 0 };
            strm.avail_out = 4096;
            strm.next_out = (Bytef *)buffer;
            int code = inflate(&strm, Z_FINISH);
            outBuffer.append(buffer, 4096 - strm.avail_out);
            if (Z_STREAM_END == code || Z_OK != code)
            {
                break;
            }
        }
    }
    inflateEnd(&strm);
    return outBuffer;
}
