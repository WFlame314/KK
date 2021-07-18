/****************************************************************************
** Meta object code from reading C++ file 'dealwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dealwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dealwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dealwindow_t {
    QByteArrayData data[16];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dealwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dealwindow_t qt_meta_stringdata_dealwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dealwindow"
QT_MOC_LITERAL(1, 11, 12), // "readytoclose"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "sendaddback"
QT_MOC_LITERAL(4, 37, 14), // "sendrefuseback"
QT_MOC_LITERAL(5, 52, 8), // "flashwin"
QT_MOC_LITERAL(6, 61, 19), // "on_closebtn_clicked"
QT_MOC_LITERAL(7, 81, 18), // "on_hidebtn_clicked"
QT_MOC_LITERAL(8, 100, 7), // "sendadd"
QT_MOC_LITERAL(9, 108, 10), // "sendrefuse"
QT_MOC_LITERAL(10, 119, 16), // "on_okbtn_clicked"
QT_MOC_LITERAL(11, 136, 20), // "on_group1btn_clicked"
QT_MOC_LITERAL(12, 157, 20), // "on_group2btn_clicked"
QT_MOC_LITERAL(13, 178, 20), // "on_group3btn_clicked"
QT_MOC_LITERAL(14, 199, 20), // "on_group4btn_clicked"
QT_MOC_LITERAL(15, 220, 18) // "on_backbtn_clicked"

    },
    "dealwindow\0readytoclose\0\0sendaddback\0"
    "sendrefuseback\0flashwin\0on_closebtn_clicked\0"
    "on_hidebtn_clicked\0sendadd\0sendrefuse\0"
    "on_okbtn_clicked\0on_group1btn_clicked\0"
    "on_group2btn_clicked\0on_group3btn_clicked\0"
    "on_group4btn_clicked\0on_backbtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dealwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    2,   85,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dealwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dealwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readytoclose(); break;
        case 1: _t->sendaddback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendrefuseback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->flashwin(); break;
        case 4: _t->on_closebtn_clicked(); break;
        case 5: _t->on_hidebtn_clicked(); break;
        case 6: _t->sendadd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendrefuse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_okbtn_clicked(); break;
        case 9: _t->on_group1btn_clicked(); break;
        case 10: _t->on_group2btn_clicked(); break;
        case 11: _t->on_group3btn_clicked(); break;
        case 12: _t->on_group4btn_clicked(); break;
        case 13: _t->on_backbtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dealwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dealwindow::readytoclose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dealwindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dealwindow::sendaddback)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (dealwindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dealwindow::sendrefuseback)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (dealwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dealwindow::flashwin)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dealwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_dealwindow.data,
    qt_meta_data_dealwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dealwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dealwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dealwindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dealwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void dealwindow::readytoclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void dealwindow::sendaddback(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dealwindow::sendrefuseback(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void dealwindow::flashwin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
