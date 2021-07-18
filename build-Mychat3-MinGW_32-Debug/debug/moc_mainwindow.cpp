/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "getfriends"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "openchatarea"
QT_MOC_LITERAL(4, 36, 10), // "readyclose"
QT_MOC_LITERAL(5, 47, 10), // "openaddwin"
QT_MOC_LITERAL(6, 58, 11), // "opendealwin"
QT_MOC_LITERAL(7, 70, 13), // "iconActivated"
QT_MOC_LITERAL(8, 84, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(9, 118, 6), // "reason"
QT_MOC_LITERAL(10, 125, 19), // "on_closebtn_clicked"
QT_MOC_LITERAL(11, 145, 18), // "on_hidebtn_clicked"
QT_MOC_LITERAL(12, 164, 12), // "myshowNormal"
QT_MOC_LITERAL(13, 177, 9), // "startchat"
QT_MOC_LITERAL(14, 187, 11), // "showTimeout"
QT_MOC_LITERAL(15, 199, 11), // "hideTimeout"
QT_MOC_LITERAL(16, 211, 17), // "on_addbtn_clicked"
QT_MOC_LITERAL(17, 229, 24) // "on_addmessagebtn_clicked"

    },
    "MainWindow\0getfriends\0\0openchatarea\0"
    "readyclose\0openaddwin\0opendealwin\0"
    "iconActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0on_closebtn_clicked\0"
    "on_hidebtn_clicked\0myshowNormal\0"
    "startchat\0showTimeout\0hideTimeout\0"
    "on_addbtn_clicked\0on_addmessagebtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       4,    0,   88,    2, 0x06 /* Public */,
       5,    1,   89,    2, 0x06 /* Public */,
       6,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   93,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getfriends(); break;
        case 1: _t->openchatarea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->readyclose(); break;
        case 3: _t->openaddwin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->opendealwin(); break;
        case 5: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 6: _t->on_closebtn_clicked(); break;
        case 7: _t->on_hidebtn_clicked(); break;
        case 8: _t->myshowNormal(); break;
        case 9: _t->startchat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->showTimeout(); break;
        case 11: _t->hideTimeout(); break;
        case 12: _t->on_addbtn_clicked(); break;
        case 13: _t->on_addmessagebtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::getfriends)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::openchatarea)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::readyclose)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::openaddwin)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::opendealwin)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MainWindow::getfriends()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::openchatarea(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::readyclose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::openaddwin(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::opendealwin()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
