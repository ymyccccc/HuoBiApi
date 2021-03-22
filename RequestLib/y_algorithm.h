#ifndef Y_ALGORITHM_H
#define Y_ALGORITHM_H

/*
 *
 *                         需要用到的一些基本算法定义在此
 *
 *
 */

#include "requestlib_global.h"
#include<QString>
#include<QMap>
#include"date.h"

class REQUESTLIBSHARED_EXPORT y_Algorithm
{
public:

    static QString urlEncode(const QString &URL);
    static QMap<Contract_Type,QString> MapContract_Type;
    static QMap<Contract_Type,QString> MapContract_Type2;
    static QMap<Symbol_Type, QString> MapSymbol_Type;
    static QMap<int, QString> MapErrCode;

    static void initMapErrCode();
    static void initData();

};


#endif // Y_ALGORITHM_H
