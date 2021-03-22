/****************************************************************************
** Meta object code from reading C++ file 'requestlib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RequestLib/requestlib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requestlib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RequestLib_t {
    QByteArrayData data[28];
    char stringdata0[451];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RequestLib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RequestLib_t qt_meta_stringdata_RequestLib = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RequestLib"
QT_MOC_LITERAL(1, 11, 22), // "GetTotalHoldingsFinish"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "Total_Holdings"
QT_MOC_LITERAL(4, 50, 13), // "totalHoldings"
QT_MOC_LITERAL(5, 64, 20), // "GetContractMsgFinish"
QT_MOC_LITERAL(6, 85, 13), // "Contract_info"
QT_MOC_LITERAL(7, 99, 3), // "msg"
QT_MOC_LITERAL(8, 103, 12), // "GetMsgFinish"
QT_MOC_LITERAL(9, 116, 3), // "Err"
QT_MOC_LITERAL(10, 120, 20), // "GetAccountInfoFinish"
QT_MOC_LITERAL(11, 141, 21), // "Contract_Account_Info"
QT_MOC_LITERAL(12, 163, 12), // "Account_Info"
QT_MOC_LITERAL(13, 176, 19), // "GetMyHoldingsFinish"
QT_MOC_LITERAL(14, 196, 31), // "QVector<Contract_Position_Info>"
QT_MOC_LITERAL(15, 228, 22), // "GetPostOrderInfoFinish"
QT_MOC_LITERAL(16, 251, 15), // "Post_Order_Info"
QT_MOC_LITERAL(17, 267, 10), // "Order_Info"
QT_MOC_LITERAL(18, 278, 24), // "GetCancleOrderInfoFinish"
QT_MOC_LITERAL(19, 303, 16), // "Cancel_Order_Msg"
QT_MOC_LITERAL(20, 320, 14), // "CancelOrderMsg"
QT_MOC_LITERAL(21, 335, 27), // "GetCancleOrderALLInfoFinish"
QT_MOC_LITERAL(22, 363, 18), // "GetOrdersMSGFinish"
QT_MOC_LITERAL(23, 382, 19), // "QVector<Order_Info>"
QT_MOC_LITERAL(24, 402, 11), // "Order_Infos"
QT_MOC_LITERAL(25, 414, 15), // "requestFinished"
QT_MOC_LITERAL(26, 430, 14), // "QNetworkReply*"
QT_MOC_LITERAL(27, 445, 5) // "reply"

    },
    "RequestLib\0GetTotalHoldingsFinish\0\0"
    "Total_Holdings\0totalHoldings\0"
    "GetContractMsgFinish\0Contract_info\0"
    "msg\0GetMsgFinish\0Err\0GetAccountInfoFinish\0"
    "Contract_Account_Info\0Account_Info\0"
    "GetMyHoldingsFinish\0QVector<Contract_Position_Info>\0"
    "GetPostOrderInfoFinish\0Post_Order_Info\0"
    "Order_Info\0GetCancleOrderInfoFinish\0"
    "Cancel_Order_Msg\0CancelOrderMsg\0"
    "GetCancleOrderALLInfoFinish\0"
    "GetOrdersMSGFinish\0QVector<Order_Info>\0"
    "Order_Infos\0requestFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RequestLib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       8,    1,   75,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,
      13,    1,   84,    2, 0x06 /* Public */,
      15,    1,   87,    2, 0x06 /* Public */,
      18,    1,   90,    2, 0x06 /* Public */,
      21,    1,   93,    2, 0x06 /* Public */,
      22,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 23,   24,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 26,   27,

       0        // eod
};

void RequestLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RequestLib *_t = static_cast<RequestLib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetTotalHoldingsFinish((*reinterpret_cast< Total_Holdings(*)>(_a[1]))); break;
        case 1: _t->GetContractMsgFinish((*reinterpret_cast< Contract_info(*)>(_a[1]))); break;
        case 2: _t->GetMsgFinish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Err((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->GetAccountInfoFinish((*reinterpret_cast< Contract_Account_Info(*)>(_a[1]))); break;
        case 5: _t->GetMyHoldingsFinish((*reinterpret_cast< QVector<Contract_Position_Info>(*)>(_a[1]))); break;
        case 6: _t->GetPostOrderInfoFinish((*reinterpret_cast< Post_Order_Info(*)>(_a[1]))); break;
        case 7: _t->GetCancleOrderInfoFinish((*reinterpret_cast< Cancel_Order_Msg(*)>(_a[1]))); break;
        case 8: _t->GetCancleOrderALLInfoFinish((*reinterpret_cast< Cancel_Order_Msg(*)>(_a[1]))); break;
        case 9: _t->GetOrdersMSGFinish((*reinterpret_cast< QVector<Order_Info>(*)>(_a[1]))); break;
        case 10: _t->requestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RequestLib::*_t)(Total_Holdings );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetTotalHoldingsFinish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(Contract_info );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetContractMsgFinish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetMsgFinish)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::Err)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(Contract_Account_Info );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetAccountInfoFinish)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(QVector<Contract_Position_Info> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetMyHoldingsFinish)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(Post_Order_Info );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetPostOrderInfoFinish)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(Cancel_Order_Msg );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetCancleOrderInfoFinish)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(Cancel_Order_Msg );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetCancleOrderALLInfoFinish)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (RequestLib::*_t)(QVector<Order_Info> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequestLib::GetOrdersMSGFinish)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject RequestLib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RequestLib.data,
      qt_meta_data_RequestLib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RequestLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RequestLib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RequestLib.stringdata0))
        return static_cast<void*>(const_cast< RequestLib*>(this));
    return QObject::qt_metacast(_clname);
}

int RequestLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void RequestLib::GetTotalHoldingsFinish(Total_Holdings _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RequestLib::GetContractMsgFinish(Contract_info _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RequestLib::GetMsgFinish(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RequestLib::Err(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RequestLib::GetAccountInfoFinish(Contract_Account_Info _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RequestLib::GetMyHoldingsFinish(QVector<Contract_Position_Info> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RequestLib::GetPostOrderInfoFinish(Post_Order_Info _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RequestLib::GetCancleOrderInfoFinish(Cancel_Order_Msg _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RequestLib::GetCancleOrderALLInfoFinish(Cancel_Order_Msg _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RequestLib::GetOrdersMSGFinish(QVector<Order_Info> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
