/****************************************************************************
** Meta object code from reading C++ file 'getprice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RequestLib/getprice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getprice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GetPrice_t {
    QByteArrayData data[15];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GetPrice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GetPrice_t qt_meta_stringdata_GetPrice = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GetPrice"
QT_MOC_LITERAL(1, 9, 17), // "GetBtcPricefinish"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "price"
QT_MOC_LITERAL(4, 34, 17), // "GetETHPricefinish"
QT_MOC_LITERAL(5, 52, 7), // "Getping"
QT_MOC_LITERAL(6, 60, 5), // "bytes"
QT_MOC_LITERAL(7, 66, 11), // "onconnected"
QT_MOC_LITERAL(8, 78, 15), // "closeConnection"
QT_MOC_LITERAL(9, 94, 21), // "onTextMessageReceived"
QT_MOC_LITERAL(10, 116, 3), // "str"
QT_MOC_LITERAL(11, 120, 7), // "onerror"
QT_MOC_LITERAL(12, 128, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(13, 157, 3), // "err"
QT_MOC_LITERAL(14, 161, 23) // "OnbinaryMessageReceived"

    },
    "GetPrice\0GetBtcPricefinish\0\0price\0"
    "GetETHPricefinish\0Getping\0bytes\0"
    "onconnected\0closeConnection\0"
    "onTextMessageReceived\0str\0onerror\0"
    "QAbstractSocket::SocketError\0err\0"
    "OnbinaryMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GetPrice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      14,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QByteArray,   10,

       0        // eod
};

void GetPrice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GetPrice *_t = static_cast<GetPrice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetBtcPricefinish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->GetETHPricefinish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Getping((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->onconnected(); break;
        case 4: _t->closeConnection(); break;
        case 5: _t->onTextMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onerror((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->OnbinaryMessageReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GetPrice::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetPrice::GetBtcPricefinish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GetPrice::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetPrice::GetETHPricefinish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GetPrice::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetPrice::Getping)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GetPrice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GetPrice.data,
      qt_meta_data_GetPrice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GetPrice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GetPrice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GetPrice.stringdata0))
        return static_cast<void*>(const_cast< GetPrice*>(this));
    return QObject::qt_metacast(_clname);
}

int GetPrice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GetPrice::GetBtcPricefinish(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GetPrice::GetETHPricefinish(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GetPrice::Getping(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
