#include "y_algorithm.h"

QMap<Contract_Type,QString> y_Algorithm::MapContract_Type = QMap<Contract_Type,QString>();
QMap<Contract_Type,QString> y_Algorithm::MapContract_Type2 = QMap<Contract_Type,QString>();
QMap<Symbol_Type,QString> y_Algorithm::MapSymbol_Type = QMap<Symbol_Type, QString>();

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

void y_Algorithm::parseReply(QString reply, QMap<QString, QString> &pair)
{


}
