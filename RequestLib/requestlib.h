#ifndef REQUESTLIB_H
#define REQUESTLIB_H

#include "requestlib_global.h"
#include "y_algorithm.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "date.h"
#include "ReqCmd.h"
#include <QQueue>


class REQUESTLIBSHARED_EXPORT RequestLib: public QObject
{
    Q_OBJECT

public:

    explicit RequestLib(QObject *parent = 0);

    /**
     * @brief SetHuoBiApiUrl
     * @param url
     * 设置火币api的url
     */
    void SetHuoBiApiUrl(QString url);

    /**
     * @brief GetContractMsg
     * 获取合约信息
     */
    void GetContractMsg(QString contract_code);
    void GetContractMsg(Symbol_Type Symboltype, Contract_Type Contracttype);

    /**
     * @brief GetMsg
     * @param method
     * 测试接口，测试货币各个api的连通性
     */
    void GetMsg(QString method);

    /**
     * @brief GetTotalHoldings
     * @param contract_code 交易合约品种代码
     * 获取当前此币种可用总持仓量
     */
    void GetTotalHoldings(QString contract_code);
    void GetTotalHoldings(Symbol_Type Symboltype, Contract_Type Contracttype);

    /**
     * @brief SetKey
     * @param accesssKey公钥
     * @param secretKey私钥
     * 设置公钥私钥
     */
    void SetKey(QString accesssKey, QString secretKey);

    /**
     * @brief GetMyTotalHoldings
     * @param Symboltype 币种
     * 获取账号信息
     */
    void GetMyAccountMsg(Symbol_Type Symboltype);

    /**
     * @brief GetMyHoldings
     * @param Symboltype
     * 获取账号当前持仓总量
     */
    void GetMyHoldings(Symbol_Type Symboltype);

    /**
     * @brief ContractOrder
     * @param orderMsg 下单信息
     * 下单接口
     */
    void ContractOrder(Contract_Order_Msg orderMsg);

    /**
     * @brief ContractCancel
     * @param Symboltype        Symbol_Type枚举值
     * @param order_id          订单ID(多个订单ID中间以","分隔,一次最多允许撤消10个订单)
     * @param client_order_id   客户订单ID(多个订单ID中间以","分隔,一次最多允许撤消10个订单
     * 撤销订单
     */
    void ContractCancel(Symbol_Type Symboltype, QString order_id, int client_order_id);

    /**
     * @brief ContractCancelAll
     * @param Symboltype
     * @param Contracttype
     * 撤销所有订单
     */
    void ContractCancelAll(Symbol_Type Symboltype, Contract_Type Contracttype);

    /**
     * @brief GetContractOrderInfo
     * @param Symboltype
     * @param order_id
     * @param client_order_id
     * 获取合约订单消息
     */
    void GetContractOrderInfo(Symbol_Type Symboltype, QString order_id, int client_order_id);

    void LightingClosePosition();

private:
    void SendErrMsg(QString reply);

    void m_GetUrlRespons(QString cmd, Method_Type type);

    void m_PostUrlRespoms(QString cmd, Method_Type type, QByteArray data);

    void m_InitMember();

    /**
     * @brief m_ParseMsg
     * @param msg
     * 切割http传过来的回复
     */
    void m_ParseMsg(QString msg);

    /**
     * @brief SplitCmd
     * @param method
     * @param Getmethod "POST" or "GET"
     * @return 组装好的命令请求
     * 根据火币api名称组装命令请求(DM)
     */
    QString SplitCmdDM(QString method, QStringList parameters, QString Getmethod);

    /**
     * @brief SplitCmd
     * @param method api名称
     * @param parameters 参数
     * @return 根据火币api名称组装命令请求
     */
    QString SplitCmd(QString method, QStringList parameters);

    /**
     * @brief ParseReply
     * @param reply //收到的回复
     * 解析收到的回复
     */
    void ParseReply(QString reply);

    /**
     * @brief ParseContractInfo
     * @return 
     */
    bool ParseContractInfo(QString reply, Contract_info& contractInfo);


    /**
     * @brief ParseTotalHoldings
     * @param reply
     * @param totalHoldings 当前持有数量  张/币
     * @return
     */
    bool ParseTotalHoldings(QString reply, Total_Holdings& totalHoldings);

    bool ParseAccountInfo(QString reply, Contract_Account_Info& Account_Info);

    bool ParsePositionInfo(QString reply, QVector<Contract_Position_Info>& Position_Infos);

    bool ParseOrderInfo(QString reply, Post_Order_Info& Order_Info);

    bool ParseCancelOrderInfo(QString reply, Cancel_Order_Msg& CancelOrderMsg);

    bool ParseGetOrderInfo(QString reply, QVector<Order_Info>& CancelOrderMsgs);

    Symbol_Type FindSymbolType(QString value);
    Contract_Type FindContractType(QString value);


    QString m_HuoBiApiUrl_;                 //火币api域名
    QNetworkAccessManager* m_ReqManager;
    QNetworkRequest* m_Request;
    QString m_Access_Key;                   //火币公钥
    QString m_Secret_Key;                   //火币私钥
    QQueue<Method_Type> m_CallMethodQueue;      //已经请求的方法队列用来解析
    QQueue<QString> m_MsgQueue;             //接收消息队列

signals:
    void GetTotalHoldingsFinish(Total_Holdings totalHoldings);
    void GetContractMsgFinish(Contract_info msg);
    void GetMsgFinish(QString msg);
    void Err(QString msg);
    void GetAccountInfoFinish(Contract_Account_Info Account_Info);
    void GetMyHoldingsFinish(QVector<Contract_Position_Info>);
    void GetPostOrderInfoFinish(Post_Order_Info Order_Info);
    void GetCancleOrderInfoFinish(Cancel_Order_Msg CancelOrderMsg);
    void GetCancleOrderALLInfoFinish(Cancel_Order_Msg CancelOrderMsg);
    void GetOrdersMSGFinish(QVector<Order_Info> Order_Infos);

public slots:
    void requestFinished(QNetworkReply* reply);


};


#endif // REQUESTLIB_H
