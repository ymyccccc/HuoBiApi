#ifndef REQCMD_H
#define REQCMD_H

/*
 *
 *                         交易所用到的api地址用宏定义在此
 *
 *
 */

// get
#define GET_CONTRACT_INFO "/api/v1/contract_contract_info"              //获取合约信息接口
#define GET_CONTRACET_OPEN_INTEREST "/api/v1/contract_open_interest"    //获取当前可用持仓量

//DM
#define GET_MY_ACCOUNT_MSG "/api/v1/contract_account_info"              //获取当前自己合约账户信息 （需要验签）
#define GET_MY_CONTRACT_ACCOUNT_INFO "/api/v1/contract_position_info"   //获取当前账号持仓信息（需要验签）
#define POST_ORDERS "/api/v1/contract_order"                            //下单
#define POST_ORDERS_CANCLE "/api/v1/contract_cancel"                    //撤单
#define POST_ORDERS_CANCLEALL "/api/v1/contract_cancelall"              //全部撤单
#define POST_GET_ORDERS_INFO  "/api/v1/contract_order_info"        //查询订单信息

//websocket
#define WEBSOCKET_GET_MARKET "market.$symbol.depth.$type"               //订阅Market Depth 数据 用来得到当前价格



//websocket订阅后缀
#define WEB_SOCK_SUBSCRIB_WS "ws"   //合约站行情请求以及订阅地址后缀

#endif // REQCMD_H
