#include "requestlib.h"
#include <QDebug>
#include "y_algorithm.h"
#include<QMessageAuthenticationCode>
#include<QStringList>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonValue>
#include <QUrl>


bool lessthan(const QString& s1, const QString& s2) {
    return s1 < s2;
}

void RequestLib::SetHuoBiApiUrl(QString url)
{
    m_HuoBiApiUrl_ = url;
}

void RequestLib::GetContractMsg(QString contract_code)
{
    QStringList parameters;
    QString param = "contract_code=" + contract_code;
    parameters << param;
    QString cmd = SplitCmd(GET_CONTRACT_INFO, parameters);
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(y_GET_CONTRACT_INFO);
    m_ReqManager->get(*m_Request);
}

void RequestLib::GetContractMsg(Symbol_Type Symboltype, Contract_Type Contracttype)
{
    QStringList parameters;
    QString param = y_Algorithm::MapSymbol_Type.value(Symboltype);
    param = QString("symbol=") + param;
    parameters << param;
    param.clear();
    param = y_Algorithm::MapContract_Type.value(Contracttype);
    param = QString("contract_type=") + param;
    parameters << param;
    QString cmd = SplitCmd(GET_CONTRACT_INFO, parameters);
    qDebug() << "sendcmd:" << cmd;
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(y_GET_CONTRACT_INFO);
    m_ReqManager->get(*m_Request);
}

void RequestLib::GetMsg(QString method)
{ 
    m_Request->setUrl("https://" + m_HuoBiApiUrl_ + method);
    m_CallMethodQueue.enqueue(y_RETRUEN_WITHOUT_PARSE);
    m_ReqManager->get(*m_Request);
}

void RequestLib::GetTotalHoldings(QString contract_code)
{
    QStringList parameters;
    QString param = "contract_code=" + contract_code;
    parameters << param;
    QString cmd = SplitCmd(GET_CONTRACET_OPEN_INTEREST, parameters);
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(y_GET_TOTAL_HOLDINGS);
    m_ReqManager->get(*m_Request);
}

void RequestLib::GetTotalHoldings(Symbol_Type Symboltype, Contract_Type Contracttype)
{
    QStringList parameters;
    QString param = y_Algorithm::MapSymbol_Type.value(Symboltype);
    param = QString("symbol=") + param;
    parameters << param;
    param.clear();
    param = y_Algorithm::MapContract_Type.value(Contracttype);
    param = QString("contract_type=") + param;
    parameters << param;
    QString cmd = SplitCmd(GET_CONTRACET_OPEN_INTEREST, parameters);
    qDebug() << "sendcmd:" << cmd;
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(y_GET_TOTAL_HOLDINGS);
    m_ReqManager->get(*m_Request);
}

void RequestLib::SetKey(QString accesssKey, QString secretKey)
{
    if (accesssKey.isEmpty() || secretKey.isEmpty()) {
        emit this->Err("未初始化KEY！/Key为空！");
    }
    this->m_Secret_Key = secretKey;
    this->m_Access_Key = accesssKey;
}

void RequestLib::GetMyAccountMsg(Symbol_Type Symboltype)
{
    QJsonObject jsonObject;
    QByteArray data;
    switch (Symboltype) {
    case y_BTC:
    {
        jsonObject["symbol"] = "BTC";
    }
        break;
    case y_ETH:
    {
        jsonObject["symbol"] = "ETH";
    }
        break;
    default:
        qDebug() << "not suporrt this Symboltype";
        break;
    }
    data = QJsonDocument(jsonObject).toJson();

    QStringList list;
    QString cmd = this->SplitCmdDM(GET_MY_ACCOUNT_MSG, list, "POST");

    m_PostUrlRespoms(cmd, y_POST_MY_ACCOUNT_MSG, data);
}

void RequestLib::GetMyHoldings(Symbol_Type Symboltype)
{
    QJsonObject jsonObject;
    QByteArray data;
    switch (Symboltype) {
    case y_BTC:
    {
        jsonObject["symbol"] = "BTC";
    }
        break;
    case y_ETH:
    {
        jsonObject["symbol"] = "ETH";
    }
        break;
    default:
        break;
    }
    data = QJsonDocument(jsonObject).toJson();

    QStringList list;
    QString cmd = this->SplitCmdDM(GET_MY_CONTRACT_ACCOUNT_INFO, list, "POST");

    //data.append("")

    m_PostUrlRespoms(cmd, y_POST_MY_HOLDINGS, data);
}

void RequestLib::ContractOrder(Contract_Order_Msg orderMsg)
{
    QJsonObject jsonObject;
    QByteArray data;

    switch (orderMsg.Symboltype) {
    case y_BTC:
    {
        jsonObject["symbol"] = "BTC";
    }
        break;
    case y_ETH:
    {
        jsonObject["symbol"] = "ETH";
    }
        break;
    default:
        break;
    }

    switch (orderMsg.type) {
    case y_This_week:
    {
        jsonObject["contract_type"] = "this_week";
    }
        break;
    case y_Next_Week:
    {
        jsonObject["contract_type"] = "next_week";
    }
        break;
    case y_Quarter:
    {
        jsonObject["contract_type"] = "quarter";
    }
        break;
    case y_Next_Quarter:
    {
        jsonObject["contract_type"] = "next_quarter";
    }
        break;
    default:
        break;
    }

    switch (orderMsg.tradetype) {
    case Open_To_Buy_More:
    {
        jsonObject["direction"] = "buy";
        jsonObject["offset"]    = "open";
    }
        break;
    case Close_To_Sell_More:
    {
        jsonObject["direction"] = "sell";
        jsonObject["offset"]    = "close";
    }
        break;
    case Open_TO_Sell_Empty:
    {
        jsonObject["direction"] = "sell";
        jsonObject["offset"]    = "open";
    }
        break;
    case Close_To_Buy_Empty:
    {
        jsonObject["direction"] = "buy";
        jsonObject["offset"]    = "close";
    }
        break;
    default:
        break;
    }

    if(!orderMsg.client_order_id.isEmpty()) {
        jsonObject["client_order_id"] = orderMsg.client_order_id.toLong();
    }

    if(!orderMsg.price.isEmpty()) {
        jsonObject["price"] = orderMsg.price.toDouble();
    }

    if(orderMsg.volume == 0) {
        qDebug() << "volume can't be 0";
        return;
    }

    jsonObject["volume"] = orderMsg.volume;
    jsonObject["lever_rate"] = orderMsg.lever_rate;
    jsonObject["order_price_type"] = orderMsg.order_price_type;

    if(!orderMsg.tp_trigger_price.isEmpty()) {
        jsonObject["tp_trigger_price"] = orderMsg.tp_trigger_price.toDouble();
        if(!orderMsg.tp_order_price_type.isEmpty()) {
            jsonObject["tp_order_price_type"] = orderMsg.tp_order_price_type;
        }

        if(!orderMsg.tp_order_price.isEmpty()) {
            jsonObject["tp_order_price"] = orderMsg.tp_order_price;
        }
    }

    if(!orderMsg.sl_trigger_price.isEmpty()) {
        jsonObject["sl_trigger_price"] = orderMsg.sl_trigger_price.toDouble();
        if(!orderMsg.sl_order_price_type.isEmpty()) {
            jsonObject["sl_order_price_type"] = orderMsg.sl_order_price_type;
        }

        if(!orderMsg.sl_order_price.isEmpty()) {
            jsonObject["sl_order_price"] = orderMsg.sl_order_price;
        }
    }

    data = QJsonDocument(jsonObject).toJson();

    QStringList list;
    QString cmd = this->SplitCmdDM(POST_ORDERS, list, "POST");

    m_PostUrlRespoms(cmd, y_Orders, data);
}

void RequestLib::ContractCancel(Symbol_Type Symboltype, QString order_id, int client_order_id)
{
    QJsonObject jsonObject;
    QByteArray data;

    jsonObject["symbol"] = y_Algorithm::MapSymbol_Type.value(Symboltype);
    if(!order_id.isEmpty()) {
        jsonObject["order_id"] = order_id;
    }

    if(client_order_id != -1) {
        jsonObject["client_order_id"] = QString::number(client_order_id);
    }

    data = QJsonDocument(jsonObject).toJson();
    QStringList list;
    QString cmd = this->SplitCmdDM(POST_ORDERS_CANCLE, list, "POST");

    m_PostUrlRespoms(cmd, y_Cancle_Orders, data);
}

void RequestLib::ContractCancelAll(Symbol_Type Symboltype, Contract_Type Contracttype)
{
    QJsonObject jsonObject;
    QByteArray data;

    jsonObject["symbol"] = y_Algorithm::MapSymbol_Type.value(Symboltype);
    jsonObject["contract_type"] = y_Algorithm::MapContract_Type.value(Contracttype);

    data = QJsonDocument(jsonObject).toJson();
    QStringList list;
    QString cmd = this->SplitCmdDM(POST_ORDERS_CANCLEALL, list, "POST");

    m_PostUrlRespoms(cmd, y_Cancle_Orders_ALL, data);
}

void RequestLib::GetContractOrderInfo(Symbol_Type Symboltype, QString order_id, int client_order_id)
{
    QJsonObject jsonObject;
    QByteArray data;

    jsonObject["symbol"] = y_Algorithm::MapSymbol_Type.value(Symboltype);
    if(!order_id.isEmpty()) {
        jsonObject["order_id"] = order_id;
    }

    if(client_order_id != -1) {
        jsonObject["client_order_id"] = QString::number(client_order_id);
    }

    data = QJsonDocument(jsonObject).toJson();
    QStringList list;
    QString cmd = this->SplitCmdDM(POST_GET_ORDERS_INFO, list, "POST");

    m_PostUrlRespoms(cmd, y_Get_Orders_MSG, data);
}

void RequestLib::SendErrMsg(QString reply)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    QJsonObject ob = document.object();
    int errcode = ob.value("err_code").toInt();
    QString errStr = y_Algorithm::MapErrCode.value(errcode);
    errStr = QString("err code:") + QString::number(errcode) + QString(", errmsg:") + errStr;
    emit Err(errStr);
}

void RequestLib::m_GetUrlRespons(QString cmd, Method_Type type)
{
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(type);
    m_ReqManager->get(*m_Request);
}

void RequestLib::m_PostUrlRespoms(QString cmd, Method_Type type, QByteArray data)
{
    m_Request->setRawHeader("Content-Type", "application/json");
    m_Request->setUrl(cmd);
    m_CallMethodQueue.enqueue(type);
    m_ReqManager->post(*m_Request, data);
}

RequestLib::RequestLib(QObject *parent):QObject(parent)
{
    qDebug() << "in RequestLib";
    m_InitMember();
    y_Algorithm::initData();
}


void RequestLib::m_InitMember()
{
    qDebug() << "in m_InitMember";
    this->m_Secret_Key = "";
    this->m_Access_Key = "";
    this->m_HuoBiApiUrl_ = "api.btcgateway.pro";
    this->m_ReqManager = new QNetworkAccessManager(this);
    this->m_Request = new QNetworkRequest();
    connect(m_ReqManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
}

QString RequestLib::SplitCmdDM(QString method, QStringList parameters, QString Getmethod)
{
    if(m_Access_Key.isEmpty() || m_Secret_Key.isEmpty()) {
        emit this->Err("未初始化KEY！/Key为空！");
        return QString();
    }
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toUTC().toString("yyyy-MM-ddThh:mm:ss");
    QString UriTime(QUrl::toPercentEncoding(current_date));
    qDebug() << "current_date = "<< current_date;
    qDebug() << "UriTime = "<< UriTime;

    if(Getmethod == "POST") {  //GET请求需要对所有请求参数进行签名，POST则不用
        parameters.clear();
    }
    parameters.append(QString("AccessKeyId=")  + m_Access_Key);
    parameters.append("SignatureMethod=HmacSHA256");
    parameters.append("SignatureVersion=2");
    parameters.append(QString("Timestamp=") + UriTime);
    qSort(parameters.begin(), parameters.end(),lessthan); //参数排序

    QString cmd = Getmethod + '\n' +  m_HuoBiApiUrl_ + '\n' + method + '\n';
    for(const auto& temp: parameters) {
        cmd = cmd + temp + '&';
    }
    cmd.remove(cmd.size()-1, 1);

    qDebug() << "CMD = " << cmd;

    QByteArray sign = QMessageAuthenticationCode::hash(cmd.toUtf8(), m_Secret_Key.toUtf8(), QCryptographicHash::Sha256).toBase64();
    qDebug() << "sign:" << sign;

    cmd.clear();
    cmd = cmd + "https://" + m_HuoBiApiUrl_ + method + "?";
    for(const auto& temp: parameters) {
        cmd = cmd + temp + '&';
    }
    cmd.remove(cmd.size()-1, 1);
    cmd = cmd + "&Signature=" + QString(QUrl::toPercentEncoding((QString(sign))));

    qDebug() << "CMD = " << cmd;
    return cmd;

}

QString RequestLib::SplitCmd(QString method, QStringList parameters)
{
    QString cmd = "https://" + m_HuoBiApiUrl_ + method;
    if(!parameters.isEmpty()) {
        cmd += '?';
        for(const auto& temp: parameters) {
            cmd = cmd + temp + '&';
        }
        cmd.remove(cmd.size()-1, 1);
    }
    return cmd;
}



bool RequestLib::ParseContractInfo(QString reply, Contract_info& contractInfo)
{
    qDebug() << "IN RequestLib::ParseContractInfo";
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
           QJsonObject ob = document.object();
           if(ob.contains("status") && ob.contains("data")) {
               QString ostatus = ob.value("status").toString();
               qDebug() << ostatus;

               QJsonArray arr = ob.value("data").toArray();
               QJsonObject ob1;
               if(arr.size() > 0) {
                   ob1 = arr.at(0).toObject();
               } else {
                   return false;
               }
               QString str = ob1.value("symbol").toString();
               qDebug() << "type is "<< str;
               contractInfo.type = this->FindSymbolType(str);
               contractInfo.contract_code = ob1.value("contract_code").toString();
               str.clear();
               str = ob1.value("contract_type").toString();
               qDebug() << "contract_type is" << str;
               contractInfo.contract_type = this->FindContractType(str);
               contractInfo.contract_size = ob1.value("contract_size").toInt();
               contractInfo.delivery_date = ob1.value("delivery_date").toString();
               contractInfo.create_date = ob1.value("create_date").toString();
               contractInfo.timestamp = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();
               qDebug() << "timestamp = " << contractInfo.timestamp;

           } else {
               return false;
           }
           return true;
    }
    return false;
}

bool RequestLib::ParseTotalHoldings(QString reply, Total_Holdings &totalHoldings)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        if(ob.contains("status") && ob.contains("data")) {
            QString status = ob.value("status").toString();
            if (status != "ok") {
                return false;
            }

            QJsonArray arr = ob.value("data").toArray();
            QJsonObject ob1;
            if(arr.size() > 0) {
                ob1 = arr.at(0).toObject();
            } else {
                return false;
            }
            totalHoldings.amount = ob1.value("volume").toInt();
            totalHoldings.volume = ob1.value("amount").toDouble();
            QString str = ob1.value("symbol").toString();
            totalHoldings.type = FindSymbolType(str);

            totalHoldings.contract_code = ob1.value("contract_code").toString();
            str.clear();
            str = ob1.value("contract_type").toString();
            totalHoldings.contract_type = this->FindContractType(str);
            totalHoldings.timestamp = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();

        } else {
            return false;
        }

        return true;
    }
    return false;
}

bool RequestLib::ParseAccountInfo(QString reply, Contract_Account_Info &Account_Info)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        QString status = ob.value("status").toString();
        if (status != "ok") {
            return false;
        }
        QJsonArray arr = ob.value("data").toArray();
        QJsonObject ob1;
        if(arr.size() > 0) {
            ob1 = arr.at(0).toObject();
        } else {
            return false;
        }

        QString symbol = ob1.value("symbol").toString();
        Account_Info.type = FindSymbolType(symbol);
        Account_Info.margin_balance = ob1.value("margin_balance").toDouble();
        Account_Info.margin_position = ob1.value("margin_position").toDouble();
        Account_Info.margin_frozen = ob1.value("margin_frozen").toDouble();
        Account_Info.margin_available = ob1.value("margin_available").toDouble();
        Account_Info.profit_real = ob1.value("profit_real").toDouble();
        Account_Info.profit_unreal = ob1.value("profit_unreal").toDouble();
        Account_Info.risk_rate = ob1.value("risk_rate").toDouble();
        Account_Info.withdraw_available = ob1.value("withdraw_available").toDouble();
        Account_Info.liquidation_price = ob1.value("liquidation_price").toDouble();
        Account_Info.lever_rate = ob1.value("lever_rate").toDouble();
        Account_Info.adjust_factor = ob1.value("adjust_factor").toDouble();
        Account_Info.margin_static = ob1.value("margin_static").toDouble();
        Account_Info.timestamp     = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();
        return true;
    }
    return false;
}

bool RequestLib::ParsePositionInfo(QString reply, QVector<Contract_Position_Info>& Position_Infos)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        QString status = ob.value("status").toString();
        if (status != "ok") {
            return false;
        }

        QJsonArray arr = ob.value("data").toArray();
        QJsonObject ob1;
        if(arr.size() == 0) {
            reply = QString::fromLocal8Bit("持仓为空");
            return true;
        }

        for(int i = 0; i < arr.size(); ++i) {
            ob1 = arr.at(i).toObject();
            Contract_Position_Info Position_Info;
            QString symbol = ob1.value("symbol").toString();
            Position_Info.type = this->FindSymbolType(symbol);
            QString str = ob1.value("contract_type").toString();
            Position_Info.contract_type = this->FindContractType(str);
            Position_Info.contract_code = ob1.value("contract_code").toString();
            Position_Info.volume = ob1.value("volume").toDouble();
            Position_Info.available = ob1.value("available").toDouble();
            Position_Info.frozen = ob1.value("frozen").toDouble();
            Position_Info.cost_open = ob1.value("cost_open").toDouble();
            Position_Info.cost_hold = ob1.value("cost_hold").toDouble();
            Position_Info.profit_unreal = ob1.value("profit_unreal").toDouble();
            Position_Info.profit_rate = ob1.value("profit_rate").toDouble();
            Position_Info.lever_rate = ob1.value("lever_rate").toDouble();
            Position_Info.position_margin = ob1.value("position_margin").toDouble();
            Position_Info.direction = ob1.value("direction").toString();
            Position_Info.profit = ob1.value("profit").toDouble();
            Position_Info.last_price = ob1.value("last_price").toDouble();
            Position_Info.timestamp  = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();
            Position_Infos.push_back(Position_Info);
        }
        return true;
    }
    return false;
}

bool RequestLib::ParseOrderInfo(QString reply, Post_Order_Info &Order_Info)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        QString status = ob.value("status").toString();
        if (status != "ok") {
            return false;
        }

        QJsonObject ob1 = ob.value("data").toObject();

        Order_Info.client_order_id = ob1.value("client_order_id").toInt();
        Order_Info.order_id_str = ob1.value("order_id_str").toString();
        Order_Info.timestamp    = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();
        return true;
    }
    return false;
}

bool RequestLib::ParseCancelOrderInfo(QString reply, Cancel_Order_Msg& CancelOrderMsg)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        QString status = ob.value("status").toString();
        if (status != "ok") {
            return false;
        }

        QJsonObject ob1 = ob.value("data").toObject();
        CancelOrderMsg.succ_msg = ob.value("successes").toString();
        CancelOrderMsg.timestamp = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();

        QJsonArray arr = ob1.value("errors").toArray();
        if(arr.size() > 0) {
            for(const auto& i: arr) {
                Cancel_Order_ErrMsg errmsg;
                QJsonObject ob2 = i.toObject();
                errmsg.err_code = ob2.value("err_code").toInt();
                errmsg.err_msg  = ob2.value("err_msg").toString();
                errmsg.order_id = ob2.value("order_id").toString();
                CancelOrderMsg.errmsgs.push_back(errmsg);
            }
        }

        return true;
    }
    return false;
}

bool RequestLib::ParseGetOrderInfo(QString reply, QVector<Order_Info> &CancelOrderMsgs)
{
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(reply.toUtf8(), &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        QJsonObject ob = document.object();
        QString status = ob.value("status").toString();
        if (status != "ok") {
            return false;
        }
        QJsonArray arr = ob.value("data").toArray();
        if(arr.size() > 0) {
            for(const auto& i: arr){
                Order_Info temp;
                QJsonObject ob1 = i.toObject();
                temp.Symboltype = FindSymbolType(ob1.value("symbol").toString());
                temp.type       = FindContractType(ob1.value("contract_type").toString());
                temp.contract_code = ob1.value("contract_code").toString();
                temp.volume     = ob1.value("volume").toDouble();
                temp.price      = ob1.value("price").toDouble();
                temp.order_price_type = ob1.value("order_price_type").toString();
                temp.order_type = ob1.value("order_type").toInt();
                temp.direction  = ob1.value("direction").toString();
                temp.offset     = ob1.value("offset").toString();
                temp.lever_rate = ob1.value("lever_rate").toInt();
                temp.order_id_str   = ob1.value("order_id_str").toString();
                temp.trade_volume   = ob1.value("trade_volume").toDouble();
                temp.trade_turnoverl    = ob1.value("trade_turnoverl").toDouble();
                temp.fee        = ob1.value("fee").toDouble();
                temp.trade_avg_price    = ob1.value("trade_avg_price").toDouble();
                temp.margin_frozen  = ob1.value("margin_frozen").toDouble();
                temp.profit     = ob1.value("profit").toDouble();
                temp.status     = ob1.value("status").toInt();
                temp.order_source   = ob1.value("order_source").toString();
                temp.fee_asset  = ob1.value("fee_asset").toString();
                temp.liquidation_type   = ob1.value("liquidation_type").toString();
                temp.is_tpsl    = ob1.value("is_tpsl").toInt();
                temp.timestamp  = QString::number(ob.value("ts").toDouble(), 'f', 0).toLongLong();
                CancelOrderMsgs.push_back(temp);
            }
            return true;
        } else {
            return false;
        }

    }

    return false;
}

Symbol_Type RequestLib::FindSymbolType(QString value)
{
    for(auto i = y_Algorithm::MapSymbol_Type.begin(); i!=y_Algorithm::MapSymbol_Type.end(); ++i) {
        if(i.value() == value) {
            return i.key();
        }
    }
}

Contract_Type RequestLib::FindContractType(QString value)
{
    for(auto i = y_Algorithm::MapContract_Type.begin(); i!=y_Algorithm::MapContract_Type.end(); ++i) {
        if(i.value() == value) {
            return i.key();
        }
    }
}

void RequestLib::requestFinished(QNetworkReply *reply)
{
   // 获取http状态码
   QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
   if(statusCode.isValid())
       qDebug() << "status code=" << statusCode.toInt();

   QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
   if(reason.isValid() && !reason.toString().isEmpty())
       qDebug() << "reason=" << reason.toString();

   QNetworkReply::NetworkError err = reply->error(); //此处需要发送消息表示接收消息失败
   if(err != QNetworkReply::NoError) {
       qDebug() << "Failed: " << reply->errorString();
       qDebug() << "fail";
       m_CallMethodQueue.dequeue();
       return;
   } else {
       // 获取返回内容，根据压入的请求解析包，
       QString msg  = QString(reply->readAll());
       qDebug() << "GetMsgFinish(msg) ! msg = " << msg;
       ParseReply(msg);
   }
}

void RequestLib::ParseReply(QString reply)
{
    Method_Type type = m_CallMethodQueue.dequeue();
    switch (type) {
    case y_RETRUEN_WITHOUT_PARSE:
        emit GetMsgFinish(reply);
        break;
    case y_GET_CONTRACT_INFO: {
        Contract_info contractInfo;
        if(!ParseContractInfo(reply, contractInfo)) {
            SendErrMsg(reply);
            return;
        }
        emit GetContractMsgFinish(contractInfo);
    }
        break;
    case y_GET_TOTAL_HOLDINGS: {
        Total_Holdings totalHoldings;
        if(!ParseTotalHoldings(reply, totalHoldings)) {
            SendErrMsg(reply);
            return;
        }
        emit GetTotalHoldingsFinish(totalHoldings);
    }
        break;
    case y_POST_MY_ACCOUNT_MSG: {
        Contract_Account_Info Account_Info;
        if(!ParseAccountInfo(reply, Account_Info)) {
            SendErrMsg(reply);
            return;
        }
        emit GetAccountInfoFinish(Account_Info);
    }
        break;
    case y_POST_MY_HOLDINGS:{
        QVector<Contract_Position_Info> Position_Infos;
        if(!ParsePositionInfo(reply, Position_Infos)){
            SendErrMsg(reply);
            return;
        }
        if (reply = QString::fromLocal8Bit("持仓为空")) {
            emit Err(reply);
            return;
        }
        emit GetMyHoldingsFinish(Position_Infos);
    }
        break;
    case y_Orders:{
        Post_Order_Info Order_Info;
        if(!ParseOrderInfo(reply,Order_Info)) {
            SendErrMsg(reply);
            return;
        }
        emit GetPostOrderInfoFinish(Order_Info);
    }
    case y_Cancle_Orders:{
        Cancel_Order_Msg CancelOrderMsg;
        if(!ParseCancelOrderInfo(reply, CancelOrderMsg)) {
            SendErrMsg(reply);
            return;
        }
        emit GetCancleOrderInfoFinish(CancelOrderMsg);
    }
        break;
    case y_Cancle_Orders_ALL:{
        Cancel_Order_Msg CancelOrderMsg;
        if(!ParseCancelOrderInfo(reply, CancelOrderMsg)) {
            SendErrMsg(reply);
            return;
        }
        emit GetCancleOrderALLInfoFinish(CancelOrderMsg);
    }
        break;
    case y_Get_Orders_MSG:{
        QVector<Order_Info> OrderInfo;
        if(ParseGetOrderInfo(reply, OrderInfo)) {
            SendErrMsg(reply);
            return;
        }
        emit GetOrdersMSGFinish(OrderInfo);
    }
        break;
    default:
        emit GetMsgFinish(reply);
        break;
    }
}

