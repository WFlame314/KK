/****************************************************************************
** Meta object code from reading C++ file 'chatspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../chatspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chatspace_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatspace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatspace_t qt_meta_stringdata_chatspace = {
    {
QT_MOC_LITERAL(0, 0, 9), // "chatspace"
QT_MOC_LITERAL(1, 10, 7), // "myclose"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "sendmessage"
QT_MOC_LITERAL(4, 31, 19), // "on_closebtn_clicked"
QT_MOC_LITERAL(5, 51, 18), // "on_sendbtn_clicked"
QT_MOC_LITERAL(6, 70, 17), // "on_minbtn_clicked"
QT_MOC_LITERAL(7, 88, 20), // "on_closebtn2_clicked"
QT_MOC_LITERAL(8, 109, 18) // "on_editmax_clicked"

    },
    "chatspace\0myclose\0\0sendmessage\0"
    "on_closebtn_clicked\0on_sendbtn_clicked\0"
    "on_minbtn_clicked\0on_closebtn2_clicked\0"
    "on_editmax_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatspace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    4,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QDate, QMetaType::QTime,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chatspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chatspace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->myclose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendmessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDate(*)>(_a[3])),(*reinterpret_cast< QTime(*)>(_a[4]))); break;
        case 2: _t->on_closebtn_clicked(); break;
        case 3: _t->on_sendbtn_clicked(); break;
        case 4: _t->on_minbtn_clicked(); break;
        case 5: _t->on_closebtn2_clicked(); break;
        case 6: _t->on_editmax_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (chatspace::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chatspace::myclose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (chatspace::*)(int , QString , QDate , QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chatspace::sendmessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject chatspace::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_chatspace.data,
    qt_meta_data_chatspace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *chatspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatspace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chatspace.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int chatspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void chatspace::myclose(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chatspace::sendmessage(int _t1, QString _t2, QDate _t3, QTime _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
