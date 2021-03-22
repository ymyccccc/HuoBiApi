#include "y_algorithm.h"
#include <QDebug>

QMap<Contract_Type,QString> y_Algorithm::MapContract_Type = QMap<Contract_Type,QString>();
QMap<Contract_Type,QString> y_Algorithm::MapContract_Type2 = QMap<Contract_Type,QString>();
QMap<Symbol_Type,QString> y_Algorithm::MapSymbol_Type = QMap<Symbol_Type, QString>();
QMap<int, QString> y_Algorithm::MapErrCode = QMap<int, QString>();

char dec2hexChar(int n)
{
    if (0 <= n && n <= 9) {
        return char(short('0') + n);
    } else if (10 <= n && n <= 15) {
        return char(short('A') + n - 10);
    } else {
        return char(0);
    }
}

void y_Algorithm::initData()
{
    if(MapContract_Type.isEmpty() && MapSymbol_Type.isEmpty()) {
        MapContract_Type.insert(y_This_week, "this_week");
        MapContract_Type.insert(y_Next_Week, "next_week");
        MapContract_Type.insert(y_Quarter, "quarter");
        MapContract_Type.insert(y_Next_Quarter, "next_quarter");

        MapContract_Type2.insert(y_This_week, "_CW");
        MapContract_Type2.insert(y_Next_Week, "_NW");
        MapContract_Type2.insert(y_Quarter, "_CQ");
        MapContract_Type2.insert(y_Next_Quarter, "_NQ");
        MapSymbol_Type.insert(y_BTC,"BTC");
        MapSymbol_Type.insert(y_ETH,"ETH");
        qDebug() << "iniData succ!";
    }
    if(MapErrCode.isEmpty()) {
        initMapErrCode();
    }

}

QString y_Algorithm::urlEncode(const QString &URL)
{
    QString result = "";
            for (int i = 0; i < URL.length(); i++) {
                char c = URL[i].toLatin1();
                if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
                    c == '/' || c == '.') {
                    result += c;
                } else {
                    int j = int(c);
                    if (j < 0) {
                        j += 256;
                    }
                    int i1, i0;
                    i1 = j / 16;
                    i0 = j - i1 * 16;
                    result += '%';
                    result += dec2hexChar(i1);
                    result += dec2hexChar(i0);
                }
            }
    return result;

}

void y_Algorithm::initMapErrCode()
{
    MapErrCode.insert(403, QString::fromLocal8Bit("无效身份"));
    MapErrCode.insert(1000, QString::fromLocal8Bit("系统异常"));
    MapErrCode.insert(1001, QString::fromLocal8Bit("系统未准备就绪"));
    MapErrCode.insert(1002, QString::fromLocal8Bit("查询异常"));
    MapErrCode.insert(1003, QString::fromLocal8Bit("操作redis异常"));
    MapErrCode.insert(1004, QString::fromLocal8Bit("系统繁忙,请稍后再试"));
    MapErrCode.insert(1010, QString::fromLocal8Bit("用户不存在"));
    MapErrCode.insert(1011, QString::fromLocal8Bit("用户会话不存在,请重试"));
    MapErrCode.insert(1012, QString::fromLocal8Bit("无效身份"));
    MapErrCode.insert(1013, QString::fromLocal8Bit("合约品种不存在"));
    MapErrCode.insert(1014, QString::fromLocal8Bit("合约不存在"));
    MapErrCode.insert(1015, QString::fromLocal8Bit("指数价格不存在"));
    MapErrCode.insert(1016, QString::fromLocal8Bit("对手价不存在"));
    MapErrCode.insert(1017, QString::fromLocal8Bit("查询订单不存在"));
    MapErrCode.insert(1018, QString::fromLocal8Bit("主账号不存在"));
    MapErrCode.insert(1019, QString::fromLocal8Bit("主账号不在开通子账号白名单里"));
    MapErrCode.insert(1020, QString::fromLocal8Bit("您的子账号数量已超出限制,请联系客服"));
    MapErrCode.insert(1021, QString::fromLocal8Bit("开户失败。您的主账号尚未开通合约交易权限,请前往开通"));
    MapErrCode.insert(1030, QString::fromLocal8Bit("输入错误"));
    MapErrCode.insert(1031, QString::fromLocal8Bit("非法的请求来源"));
    MapErrCode.insert(1032, QString::fromLocal8Bit("访问次数超出限制"));
    MapErrCode.insert(1033, QString::fromLocal8Bit("合约周期字段值错误"));
    MapErrCode.insert(1034, QString::fromLocal8Bit("报单价格类型字段值错误"));
    MapErrCode.insert(1035, QString::fromLocal8Bit("报单方向字段值错误"));
    MapErrCode.insert(1036, QString::fromLocal8Bit("报单开平字段值错误"));
    MapErrCode.insert(1037, QString::fromLocal8Bit("倍数不符合要求,请联系客服"));
    MapErrCode.insert(1038, QString::fromLocal8Bit("下单价格超出精度限制,请修改后下单"));
    MapErrCode.insert(1039, QString::fromLocal8Bit("买入价必须低于{0}{1},卖出价必须高于{2}{3}"));
    MapErrCode.insert(1040, QString::fromLocal8Bit("下单数量不能为空或者不能小于0, 请修改后下单"));
    MapErrCode.insert(1041, QString::fromLocal8Bit("下单数量超出限制 ({0}张),请修改后下单"));
    MapErrCode.insert(1042, QString::fromLocal8Bit("下单数量+挂单数量+持仓数量超过了单用户多仓持仓限制({0}张),请修改后下单"));
    MapErrCode.insert(1043, QString::fromLocal8Bit("下单数量+挂单数量+持仓数量超过了单用户空仓持仓限制({0}张), 请修改后下单"));
    MapErrCode.insert(1044, QString::fromLocal8Bit("触发平台限仓,请修改后下单"));
    MapErrCode.insert(1045, QString::fromLocal8Bit("当前有挂单,无法切换倍数"));
    MapErrCode.insert(1046, QString::fromLocal8Bit("当前合约持仓不存在"));
    MapErrCode.insert(1047, QString::fromLocal8Bit("可用担保资产不足"));
    MapErrCode.insert(1048, QString::fromLocal8Bit("可平量不足"));
    MapErrCode.insert(1049, QString::fromLocal8Bit("暂不支持市价开仓"));
    MapErrCode.insert(1050, QString::fromLocal8Bit("客户报单号重复"));
    MapErrCode.insert(1051, QString::fromLocal8Bit("没有可撤销的订单"));
    MapErrCode.insert(1052, QString::fromLocal8Bit("批量撤单、下单的订单数量超过平台限制数量"));
    MapErrCode.insert(1053, QString::fromLocal8Bit("无法获取最新价格区间"));
    MapErrCode.insert(1054, QString::fromLocal8Bit("无法获取最新价"));
    MapErrCode.insert(1055, QString::fromLocal8Bit("价格不合理, 下单后将导致账户权益小于0 , 请修改价格后下单"));
    MapErrCode.insert(1056, QString::fromLocal8Bit("结算中,暂时无法下单/撤单"));
    MapErrCode.insert(1057, QString::fromLocal8Bit("暂停交易中,暂时无法下单"));
    MapErrCode.insert(1058, QString::fromLocal8Bit("停牌中,暂时无法下单"));
    MapErrCode.insert(1059, QString::fromLocal8Bit("交割中,暂时无法下单/撤单"));
    MapErrCode.insert(1060, QString::fromLocal8Bit("合约处于非交易状态,暂时无法下单"));
    MapErrCode.insert(1061, QString::fromLocal8Bit("订单不存在"));
    MapErrCode.insert(1062, QString::fromLocal8Bit("撤单中,请耐心等待"));
    MapErrCode.insert(1063, QString::fromLocal8Bit("订单已成交"));
    MapErrCode.insert(1064, QString::fromLocal8Bit("报单主键冲突"));
    MapErrCode.insert(1065, QString::fromLocal8Bit("客户报单号不是整数"));
    MapErrCode.insert(1066, QString::fromLocal8Bit("{0}字段不能为空"));
    MapErrCode.insert(1067, QString::fromLocal8Bit("{0}字段不合法"));
    MapErrCode.insert(1068, QString::fromLocal8Bit("导出错误"));
    MapErrCode.insert(1069, QString::fromLocal8Bit("价格不合理"));
    MapErrCode.insert(1070, QString::fromLocal8Bit("数据为空,无法导出"));
    MapErrCode.insert(1071, QString::fromLocal8Bit("订单已撤,无法撤单"));
    MapErrCode.insert(1072, QString::fromLocal8Bit("卖出价必须低于{0}{1}"));
    MapErrCode.insert(1073, QString::fromLocal8Bit("仓位异常,请联系客服"));
    MapErrCode.insert(1074, QString::fromLocal8Bit("下单异常,请联系客服"));
    MapErrCode.insert(1075, QString::fromLocal8Bit("价格不合理, 下单后将导致担保资产率小于0 , 请修改价格后下单"));
    MapErrCode.insert(1076, QString::fromLocal8Bit("盘口无数据,请稍后再试"));
    MapErrCode.insert(1077, QString::fromLocal8Bit("交割结算中,当前品种资金查询失败"));
    MapErrCode.insert(1078, QString::fromLocal8Bit("交割结算中,部分品种资金查询失败"));
    MapErrCode.insert(1079, QString::fromLocal8Bit("交割结算中,当前品种持仓查询失败"));
    MapErrCode.insert(1080, QString::fromLocal8Bit("交割结算中,部分品种持仓查询失败"));
    MapErrCode.insert(1081, QString::fromLocal8Bit("{0}合约计划委托订单数量不得超过{1}"));
    MapErrCode.insert(1082, QString::fromLocal8Bit("触发类型参数错误"));
    MapErrCode.insert(1083, QString::fromLocal8Bit("您的仓位已进入强平接管,暂时无法下单"));
    MapErrCode.insert(1084, QString::fromLocal8Bit("您的合约API挂单接口被禁用,请于{0} (GMT+8) 后再试"));
    MapErrCode.insert(1085, QString::fromLocal8Bit("计划委托下单失败,请修改价格再次下单或联系客服"));
    MapErrCode.insert(1086, QString::fromLocal8Bit("{0}合约暂时限制{1}端开仓,请联系客服"));
    MapErrCode.insert(1087, QString::fromLocal8Bit("{0}合约暂时限制{1}端平仓,请联系客服"));
    MapErrCode.insert(1088, QString::fromLocal8Bit("{0}合约暂时限制{1}端撤单,请联系客服"));
    MapErrCode.insert(1089, QString::fromLocal8Bit("{0}账户暂时限制划转,请联系客服"));
    MapErrCode.insert(1090, QString::fromLocal8Bit("担保资产率小于0, 无法下单"));
    MapErrCode.insert(1091, QString::fromLocal8Bit("账户权益小于0, 无法下单"));
    MapErrCode.insert(1092, QString::fromLocal8Bit("闪电平仓取盘口第{0}档的价格, 下单后将导致账户权益小于0 , 请改为手动输入价格或使用对手价下单"));
    MapErrCode.insert(1093, QString::fromLocal8Bit("闪电平仓取盘口第{0}档的价格, 下单后将导致担保资产率小于0 , 请改为手动输入价格或使用对手价下单"));
    MapErrCode.insert(1094, QString::fromLocal8Bit("倍数不能为空, 请切换倍数或联系客服"));
    MapErrCode.insert(1095, QString::fromLocal8Bit("合约处于非交易状态, 暂时无法切换倍数"));
    MapErrCode.insert(1100, QString::fromLocal8Bit("您没有开仓权限,请联系客服"));
    MapErrCode.insert(1101, QString::fromLocal8Bit("您没有平仓权限,请联系客服"));
    MapErrCode.insert(1102, QString::fromLocal8Bit("您没有转入权限,请联系客服"));
    MapErrCode.insert(1103, QString::fromLocal8Bit("您没有转出权限,请联系客服"));
    MapErrCode.insert(1104, QString::fromLocal8Bit("合约交易受限,当前禁止交易"));
    MapErrCode.insert(1105, QString::fromLocal8Bit("合约交易受限,当前只能平仓"));
    MapErrCode.insert(1106, QString::fromLocal8Bit("合约交割结算中,暂时无法划转"));
    MapErrCode.insert(1108, QString::fromLocal8Bit("Dubbo调用异常"));
    MapErrCode.insert(1109, QString::fromLocal8Bit("子账号没有开仓权限,请联系客服"));
    MapErrCode.insert(1110, QString::fromLocal8Bit("子账号没有平仓权限,请联系客服"));
    MapErrCode.insert(1111, QString::fromLocal8Bit("子账号没有入金权限,请联系客服"));
    MapErrCode.insert(1112, QString::fromLocal8Bit("子账号没有出金权限,请联系客服"));
    MapErrCode.insert(1113, QString::fromLocal8Bit("子账号没有交易权限,请登录主账号授权"));
    MapErrCode.insert(1114, QString::fromLocal8Bit("子账号没有划转权限,请登录主账号授权"));
    MapErrCode.insert(1115, QString::fromLocal8Bit("您没有访问此子账号的权限"));
    MapErrCode.insert(1200, QString::fromLocal8Bit("登录失败,请重试"));
    MapErrCode.insert(1220, QString::fromLocal8Bit("您尚未开通合约交易,无访问权限"));
    MapErrCode.insert(1221, QString::fromLocal8Bit("币币账户总资产不满足合约开通条件"));
    MapErrCode.insert(1222, QString::fromLocal8Bit("开户天数不满足合约开通条件"));
    MapErrCode.insert(1223, QString::fromLocal8Bit("VIP等级不满足合约开通条件"));
    MapErrCode.insert(1224, QString::fromLocal8Bit("您所在的国家/地区不满足合约开通条件"));
    MapErrCode.insert(1225, QString::fromLocal8Bit("开通合约失败"));
    MapErrCode.insert(1226, QString::fromLocal8Bit("合约已开户,无法重复开户"));
    MapErrCode.insert(1227, QString::fromLocal8Bit("火币合约暂不支持子账户,请返回退出子账户,切换主账户登录"));
    MapErrCode.insert(1228, QString::fromLocal8Bit("您尚未开通合约交易, 请先开通"));
    MapErrCode.insert(1229, QString::fromLocal8Bit("重复同意协议"));
    MapErrCode.insert(1230, QString::fromLocal8Bit("您尚未做风险认证"));
    MapErrCode.insert(1231, QString::fromLocal8Bit("您尚未做身份认证"));
    MapErrCode.insert(1232, QString::fromLocal8Bit("您上传的图片格式/大小不符合要求,请重新上传"));
    MapErrCode.insert(1233, QString::fromLocal8Bit("您尚未开通高倍数协议 (使用高倍数请先使用主账号登录web或APP端同意高倍数协议)"));
    MapErrCode.insert(1234, QString::fromLocal8Bit("{0}合约开仓委托订单数量不得超过{1}"));
    MapErrCode.insert(1235, QString::fromLocal8Bit("{0}合约平仓委托订单数量不得超过{1}"));
    MapErrCode.insert(1250, QString::fromLocal8Bit("无法获取HT_token"));
    MapErrCode.insert(1251, QString::fromLocal8Bit("无法获取BTC净资产,请稍后再试"));
    MapErrCode.insert(1252, QString::fromLocal8Bit("无法获取币币账户资产,请稍后再试"));
    MapErrCode.insert(1253, QString::fromLocal8Bit("签名验证错误"));
    MapErrCode.insert(1066, QString::fromLocal8Bit("{0}字段不能为空"));
    MapErrCode.insert(1254, QString::fromLocal8Bit("子账号无权限开通合约，请前往web端登录主账号开通"));
    MapErrCode.insert(1300, QString::fromLocal8Bit("划转失败"));
    MapErrCode.insert(1301, QString::fromLocal8Bit("可划转余额不足"));
    MapErrCode.insert(1302, QString::fromLocal8Bit("系统划转错误"));
    MapErrCode.insert(1303, QString::fromLocal8Bit("单笔转出的数量不能低于{0}{1}"));
    MapErrCode.insert(1304, QString::fromLocal8Bit("单笔转出的数量不能高于{0}{1}"));
    MapErrCode.insert(1305, QString::fromLocal8Bit("单笔转入的数量不能低于{0}{1}"));
    MapErrCode.insert(1306, QString::fromLocal8Bit("单笔转入的数量不能高于{0}{1}"));
    MapErrCode.insert(1307, QString::fromLocal8Bit("您当日累计转出量超过{0}{1}, 暂无法转出"));
    MapErrCode.insert(1308, QString::fromLocal8Bit("您当日累计转入量超过{0}{1}, 暂无法转入"));
    MapErrCode.insert(1309, QString::fromLocal8Bit("您当日累计净转出量超过{0}{1}, 暂无法转出"));
    MapErrCode.insert(1310, QString::fromLocal8Bit("您当日累计净转入量超过{0}{1}, 暂无法转入"));
    MapErrCode.insert(1311, QString::fromLocal8Bit("超过平台当日累计最大转出量限制, 暂无法转出"));
    MapErrCode.insert(1312, QString::fromLocal8Bit("超过平台当日累计最大转入量限制, 暂无法转入"));
    MapErrCode.insert(1313, QString::fromLocal8Bit("超过平台当日累计最大净转出量限制, 暂无法转出"));
    MapErrCode.insert(1314, QString::fromLocal8Bit("超过平台当日累计最大净转入量限制, 暂无法转入"));
    MapErrCode.insert(1315, QString::fromLocal8Bit("划转类型错误"));
    MapErrCode.insert(1316, QString::fromLocal8Bit("划转冻结失败"));
    MapErrCode.insert(1317, QString::fromLocal8Bit("划转解冻失败"));
    MapErrCode.insert(1318, QString::fromLocal8Bit("划转确认失败"));
    MapErrCode.insert(1319, QString::fromLocal8Bit("查询可划转金额失败"));
    MapErrCode.insert(1320, QString::fromLocal8Bit("此合约在非交易状态中, 无法进行系统划转"));
    MapErrCode.insert(1321, QString::fromLocal8Bit("划转失败, 请稍后重试或联系客服"));
    MapErrCode.insert(1322, QString::fromLocal8Bit("划转金额必须大于0"));
    MapErrCode.insert(1323, QString::fromLocal8Bit("服务异常, 划转失败, 请稍后再试"));
    MapErrCode.insert(1325, QString::fromLocal8Bit("设置交易单位失败"));
    MapErrCode.insert(1326, QString::fromLocal8Bit("获取交易单位失败"));
    MapErrCode.insert(1327, QString::fromLocal8Bit("无划转权限, 划转失败, 请联系客服"));
    MapErrCode.insert(1328, QString::fromLocal8Bit("无划转权限, 划转失败, 请联系客服"));
    MapErrCode.insert(1329, QString::fromLocal8Bit("无划转权限, 划转失败, 请联系客服"));
    MapErrCode.insert(1330, QString::fromLocal8Bit("无划转权限, 划转失败, 请联系客服"));
    MapErrCode.insert(1331, QString::fromLocal8Bit("超出划转精度限制(8位), 请修改后操作"));
    MapErrCode.insert(1332, QString::fromLocal8Bit("永续合约不存在"));
    MapErrCode.insert(1333, QString::fromLocal8Bit("开通跟单吃单协议失败"));
    MapErrCode.insert(1334, QString::fromLocal8Bit("查询跟单吃单协议失败"));
    MapErrCode.insert(1335, QString::fromLocal8Bit("查询跟单吃单二次确认设置失败"));
    MapErrCode.insert(1336, QString::fromLocal8Bit("更新跟单吃单二次确认设置失败"));
    MapErrCode.insert(1337, QString::fromLocal8Bit("查询跟单吃单设置失败"));
    MapErrCode.insert(1338, QString::fromLocal8Bit("更新跟单吃单设置失败"));
    MapErrCode.insert(1339, QString::fromLocal8Bit("昵称含有不合法词汇, 请修改"));
    MapErrCode.insert(1340, QString::fromLocal8Bit("昵称已被使用, 请修改"));
    MapErrCode.insert(1341, QString::fromLocal8Bit("报名阶段已结束"));
    MapErrCode.insert(1342, QString::fromLocal8Bit("子账号无法设置昵称"));
    MapErrCode.insert(1343, QString::fromLocal8Bit("指标失效, 请重新设置"));
    MapErrCode.insert(1344, QString::fromLocal8Bit("抱歉, 目前可最多对{0}个合约创建行情提醒"));
    MapErrCode.insert(1345, QString::fromLocal8Bit("抱歉, {0}合约目前可最多创建{1}个提醒"));
    MapErrCode.insert(1346, QString::fromLocal8Bit("该指标已存在, 请勿重复设置"));
    MapErrCode.insert(1347, QString::fromLocal8Bit("{0}参数错误, 请修改"));
    MapErrCode.insert(1348, QString::fromLocal8Bit("该合约不支持全仓模式"));
    MapErrCode.insert(1349, QString::fromLocal8Bit("委托单倍数与当前持仓的倍数不符, 请先切换倍数"));
    MapErrCode.insert(1401, QString::fromLocal8Bit("委托价必须小于行权价"));
    MapErrCode.insert(1403, QString::fromLocal8Bit("{0}合约止盈止损订单的委托数量不得超过{1}"));
    MapErrCode.insert(1404, QString::fromLocal8Bit("止盈止损订单仅支持与开仓订单绑定"));
    MapErrCode.insert(1405, QString::fromLocal8Bit("止盈价不得{0}{1}{2}"));
    MapErrCode.insert(1406, QString::fromLocal8Bit("您的抽奖次数已用完"));
    MapErrCode.insert(1407, QString::fromLocal8Bit("止损价不得{0}{1}{2}"));
    MapErrCode.insert(1408, QString::fromLocal8Bit("该止盈止损委托单未生效, 无法撤销"));
    MapErrCode.insert(1409, QString::fromLocal8Bit("您没有止盈止损订单权限,请联系客服"));
    MapErrCode.insert(12001, QString::fromLocal8Bit("无效的提交时间"));
    MapErrCode.insert(12002, QString::fromLocal8Bit("错误的签名版本"));
    MapErrCode.insert(12003, QString::fromLocal8Bit("错误的签名方法"));
    MapErrCode.insert(12004, QString::fromLocal8Bit("密钥已经过期"));
    MapErrCode.insert(12005, QString::fromLocal8Bit("ip地址错误"));
    MapErrCode.insert(12006, QString::fromLocal8Bit("提交时间不能为空"));
    MapErrCode.insert(12007, QString::fromLocal8Bit("公钥错误"));
    MapErrCode.insert(12008, QString::fromLocal8Bit("失败"));
    MapErrCode.insert(12009, QString::fromLocal8Bit("用户被锁定或不存在"));
}
