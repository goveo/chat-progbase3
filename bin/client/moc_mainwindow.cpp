/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/myclient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[458];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "slotReadyRead"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "slotError"
QT_MOC_LITERAL(4, 36, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 65, 13), // "slotConnected"
QT_MOC_LITERAL(6, 79, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(7, 101, 32), // "on_messageLineEdit_returnPressed"
QT_MOC_LITERAL(8, 134, 25), // "on_settingsButton_clicked"
QT_MOC_LITERAL(9, 160, 25), // "on_settingsButton_pressed"
QT_MOC_LITERAL(10, 186, 38), // "on_usersOnlineWidget_itemDoub..."
QT_MOC_LITERAL(11, 225, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 242, 4), // "item"
QT_MOC_LITERAL(13, 247, 32), // "on_usersOnlineWidget_itemPressed"
QT_MOC_LITERAL(14, 280, 25), // "on_contactsButton_pressed"
QT_MOC_LITERAL(15, 306, 26), // "on_contactsButton_released"
QT_MOC_LITERAL(16, 333, 30), // "on_messageLineEdit_textChanged"
QT_MOC_LITERAL(17, 364, 4), // "text"
QT_MOC_LITERAL(18, 369, 25), // "on_changeIpButton_clicked"
QT_MOC_LITERAL(19, 395, 15), // "isRequestedByMe"
QT_MOC_LITERAL(20, 411, 8), // "username"
QT_MOC_LITERAL(21, 420, 13), // "isRequestedMe"
QT_MOC_LITERAL(22, 434, 23) // "on_MainWindow_destroyed"

    },
    "MainWindow\0slotReadyRead\0\0slotError\0"
    "QAbstractSocket::SocketError\0slotConnected\0"
    "on_sendButton_clicked\0"
    "on_messageLineEdit_returnPressed\0"
    "on_settingsButton_clicked\0"
    "on_settingsButton_pressed\0"
    "on_usersOnlineWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_usersOnlineWidget_itemPressed\0"
    "on_contactsButton_pressed\0"
    "on_contactsButton_released\0"
    "on_messageLineEdit_textChanged\0text\0"
    "on_changeIpButton_clicked\0isRequestedByMe\0"
    "username\0isRequestedMe\0on_MainWindow_destroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    1,  103,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    1,  111,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    1,  115,    2, 0x08 /* Private */,
      21,    1,  118,    2, 0x08 /* Private */,
      22,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->slotConnected(); break;
        case 3: _t->on_sendButton_clicked(); break;
        case 4: _t->on_messageLineEdit_returnPressed(); break;
        case 5: _t->on_settingsButton_clicked(); break;
        case 6: _t->on_settingsButton_pressed(); break;
        case 7: _t->on_usersOnlineWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_usersOnlineWidget_itemPressed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_contactsButton_pressed(); break;
        case 10: _t->on_contactsButton_released(); break;
        case 11: _t->on_messageLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_changeIpButton_clicked(); break;
        case 13: { bool _r = _t->isRequestedByMe((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->isRequestedMe((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: _t->on_MainWindow_destroyed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
