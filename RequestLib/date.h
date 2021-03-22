#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QVector>

/*
 *
 *                         交易所用到的结构体定义在此data.h
 *
 *
 */
//合约类型
enum Contract_Type  {
    y_This_week,
    y_Next_Week,
    y_Quarter,
    y_Next_Quarter,
};

enum Trade_Type {
    Open_To_Buy_More,       //开多
    Close_To_Sell_More,     //平多
    Open_TO_Sell_Empty,     //开空
    Close_To_Buy_Empty,     //平空
};

//合约币种
enum Symbol_Type  {
    y_BTC,
    y_ETH,
};

//发送命令类型
enum Method_Type {
    y_RETRUEN_WITHOUT_PARSE,  //不需要解析直接返回
    y_GET_CONTRACT_INFO,      //获取币种合约信息
    y_GET_TOTAL_HOLDINGS,     //获取当前可用合约总量
    y_POST_MY_ACCOUNT_MSG,    //获取当前账户信息
    y_POST_MY_HOLDINGS,       //获取当前账户持仓信息
    y_Orders,                 //下单
    y_Cancle_Orders,          //撤单
    y_Cancle_Orders_ALL,      //全部撤单
    y_Get_Orders_MSG,         //查询订单信息
};

//合约信息
struct Contract_info{
    Symbol_Type type;
    QString contract_code;  //合约代码
    Contract_Type contract_type; //合约类型
    int contract_size;      //合约面值 即1张合约对应多少美元
    QString delivery_date;  //截止日期
    QString create_date;    //开始日期
    long long timestamp;      //请求时间戳
    Contract_info() {
        type = y_BTC;
        contract_code = "";
        contract_type = y_This_week;
        contract_size = 100;
        delivery_date = "";
        create_date = "";
        timestamp = 0;
    }
};

struct Total_Holdings {
    int volume;  //持仓量（张）
    double amount; //持仓量(币)
    Symbol_Type type;
    QString contract_code;  //合约代码
    Contract_Type contract_type; //合约类型
    long long timestamp;      //请求时间戳
    Total_Holdings() {
        volume = 0;
        amount = 0;
        type = y_BTC;
        contract_type = y_This_week;
        contract_code = "";
    }
};

struct Contract_Account_Info {
    Symbol_Type type;
    double margin_balance;          //账户权益
    double margin_position;         //当前持有仓位占有保证金
    double margin_frozen;           //冻结保证金
    double margin_available;        //可用保证金
    double profit_real;             //已实现盈亏
    double profit_unreal;           //未实现盈亏
    double risk_rate;               //保证金率
    double liquidation_price;       //预估强平价
    double withdraw_available;      //可划转数量
    double lever_rate;              //杠杆倍数
    double adjust_factor;           //调整系数
    double margin_static;          //静态权益
    long long timestamp;      //请求时间戳
};

struct Contract_Position_Info {
    Symbol_Type type;
    QString contract_code;
    Contract_Type contract_type;
    double volume;                  //持仓量
    double available;               //可持仓量
    double frozen;                  //冻结数量
    double cost_open;               //开仓均价
    double cost_hold;               //持仓均价
    double profit_unreal;           //未实现盈亏
    double profit_rate;             //收益率
    double profit;                  //收益
    double position_margin;         //持仓保证金
    double lever_rate;              //杠杆倍数
    QString direction;              //"buy":买 "sell":卖
    double last_price;              //最新价
    long long timestamp;      //请求时间戳
};

struct Post_Order_Info {
    QString order_id_str;           //string类型订单ID
    int client_order_id;            //用户下单时填写的客户端订单ID，没填则不返回
    long long timestamp;      //请求时间戳
};

struct Cancel_Order_ErrMsg{
    QString order_id;
    int err_code;
    QString err_msg;
};



struct Cancel_Order_Msg{
    QString succ_msg;
    QVector<Cancel_Order_ErrMsg> errmsgs;
    long long timestamp;      //请求时间戳
};

struct Contract_Order_Msg{
    Symbol_Type Symboltype; //必填
    Contract_Type type;     //必填
    Trade_Type tradetype;   //必填
    QString client_order_id;    //客户自己填写和维护，必须为数字,请注意必须小于等于9223372036854775807
    QString price;
    long volume;                //张数   必填
    int lever_rate;             //杠杆倍数[“开仓”若有10倍多单，就不能再下20倍多单, "平仓"可以不填杠杆倍数;首次使用高倍杠杆(>20倍)，请使用主账号登录web端同意高倍杠杆协议后，才能使用接口下高倍杠杆(>20倍)]   必填

    //订单报价类型 "limit":限价 "opponent":对手价 "post_only":只做maker单,post only下单只受用户持仓数量限制,optimal_5：最优5档、optimal_10：最优10档、optimal_20：最优20档，
    //ioc:IOC订单，fok：FOK订单, "opponent_ioc"： 对手价-IOC下单，"optimal_5_ioc"：最优5档-IOC下单，"optimal_10_ioc"：最优10档-IOC下单，"optimal_20_ioc"：最优20档-IOC下单,
    //"opponent_fok"： 对手价-FOK下单，"optimal_5_fok"：最优5档-FOK下单，"optimal_10_fok"：最优10档-FOK下单，"optimal_20_fok"：最优20档-FOK下单
    QString order_price_type;    //必填
    QString tp_trigger_price;         //止盈触发价格
    QString tp_order_price;           //止盈委托价格
    QString tp_order_price_type;    //止盈委托类型  不填默认为limit; 限价：limit ，最优5档：optimal_5，最优10档：optimal_10，最优20档：optimal_20

    QString sl_trigger_price;         //止损触发价格
    QString sl_order_price;           //止损委托价格
    QString sl_order_price_type;    //止损委托类型 不填默认为limit; 限价：limit ，最优5档：optimal_5，最优10档：optimal_10，最优20档：optimal_20
};

struct Order_Info{
    Symbol_Type Symboltype; //必填
    Contract_Type type;     //必填
    QString contract_code;  //合约代码
    double volume;          //委托数量
    double price;           //委托价格
    QString order_price_type; //订单报价类型 订单报价类型 订单报价类型 "limit":限价 "opponent":对手价 "post_only":只做maker单,post only下单只受用户持仓数量限制,optimal_5：最优5档、optimal_10：最优10档、optimal_20：最优20档，ioc:IOC订单，fok：FOK订单
    QString direction;      //买卖方向 "buy":买 "sell":卖
    QString offset;         //开平方向 "open":开 "close":平
    int     lever_rate;     //杠杆倍数 1\5\10\20
    long    order_id;       //订单ID
    QString order_id_str;   //String类型订单ID
    long    client_order_id;//客户订单ID
    long    created_at;     //创建时间
    long    canceled_at;    //撤单时间
    double  trade_volume;   //成交数量
    double  trade_turnoverl;//成交金额
    double  fee;            //手续费
    double  trade_avg_price;//成交均价
    double  margin_frozen;  //冻结保证金
    double  profit;         //收益
    int     status;         //订单状态 (1准备提交 2准备提交 3已提交 4部分成交 5部分成交已撤单 6全部成交 7已撤单 11撤单中)
    int     order_type;     //订单类型1:报单 、 2:撤单 、 3:强平、4:交割
    QString order_source;   //订单来源 (system:系统、web:用户网页、api:用户API、m:用户M站、risk:风控系统、settlement:交割结算、ios：ios客户端、android：安卓客户端、windows：windows客户端、mac：mac客户端、trigger：计划委托触发、tpsl:止盈止损触发）
    QString fee_asset;      //手续费币种（"BTC","ETH"...）
    QString liquidation_type;//强平类型 0:非强平类型，1：多空轧差， 2:部分接管，3：全部接管
    int     is_tpsl;        //是否设置止盈止损 1：是；0：否
    long long timestamp;      //请求时间戳
};



#endif // DATE_H
