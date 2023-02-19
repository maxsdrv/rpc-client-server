/****************************************************************************
** Meta object code from reading C++ file 'test_rpc_grpc.qpb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "test_rpc_grpc.qpb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_rpc_grpc.qpb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient_t {
    QByteArrayData data[14];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient_t qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient = {
    {
QT_MOC_LITERAL(0, 0, 38), // "qtprotobuf::testrpc::EchoServ..."
QT_MOC_LITERAL(1, 39, 4), // "Echo"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 32), // "qtprotobuf::testrpc::EchoRequest"
QT_MOC_LITERAL(4, 78, 3), // "arg"
QT_MOC_LITERAL(5, 82, 14), // "const QObject*"
QT_MOC_LITERAL(6, 97, 7), // "context"
QT_MOC_LITERAL(7, 105, 53), // "std::function<void(QtProtobuf..."
QT_MOC_LITERAL(8, 159, 8), // "callback"
QT_MOC_LITERAL(9, 168, 33), // "qtprotobuf::testrpc::EchoRequ..."
QT_MOC_LITERAL(10, 202, 8), // "QJSValue"
QT_MOC_LITERAL(11, 211, 13), // "errorCallback"
QT_MOC_LITERAL(12, 225, 34), // "qtprotobuf::testrpc::EchoResp..."
QT_MOC_LITERAL(13, 260, 3) // "ret"

    },
    "qtprotobuf::testrpc::EchoServiceClient\0"
    "Echo\0\0qtprotobuf::testrpc::EchoRequest\0"
    "arg\0const QObject*\0context\0"
    "std::function<void(QtProtobuf::QGrpcCallReplyShared)>\0"
    "callback\0qtprotobuf::testrpc::EchoRequest*\0"
    "QJSValue\0errorCallback\0"
    "qtprotobuf::testrpc::EchoResponse*\0"
    "ret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtprotobuf__testrpc__EchoServiceClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x02 /* Public */,
       1,    3,   36,    2, 0x02 /* Public */,
       1,    3,   43,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 10, 0x80000000 | 10,    4,    8,   11,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 12, 0x80000000 | 10,    4,   13,   11,

       0        // eod
};

void qtprotobuf::testrpc::EchoServiceClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EchoServiceClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Echo((*reinterpret_cast< const qtprotobuf::testrpc::EchoRequest(*)>(_a[1])),(*reinterpret_cast< const QObject*(*)>(_a[2])),(*reinterpret_cast< const std::function<void(QtProtobuf::QGrpcCallReplyShared)>(*)>(_a[3]))); break;
        case 1: _t->Echo((*reinterpret_cast< qtprotobuf::testrpc::EchoRequest*(*)>(_a[1])),(*reinterpret_cast< const QJSValue(*)>(_a[2])),(*reinterpret_cast< const QJSValue(*)>(_a[3]))); break;
        case 2: _t->Echo((*reinterpret_cast< qtprotobuf::testrpc::EchoRequest*(*)>(_a[1])),(*reinterpret_cast< qtprotobuf::testrpc::EchoResponse*(*)>(_a[2])),(*reinterpret_cast< const QJSValue(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qtprotobuf::testrpc::EchoRequest >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qtprotobuf::testrpc::EchoRequest* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qtprotobuf::testrpc::EchoRequest* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qtprotobuf::testrpc::EchoResponse* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qtprotobuf::testrpc::EchoServiceClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QtProtobuf::QAbstractGrpcClient::staticMetaObject>(),
    qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient.data,
    qt_meta_data_qtprotobuf__testrpc__EchoServiceClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtprotobuf::testrpc::EchoServiceClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtprotobuf::testrpc::EchoServiceClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtprotobuf__testrpc__EchoServiceClient.stringdata0))
        return static_cast<void*>(this);
    return QtProtobuf::QAbstractGrpcClient::qt_metacast(_clname);
}

int qtprotobuf::testrpc::EchoServiceClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtProtobuf::QAbstractGrpcClient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
