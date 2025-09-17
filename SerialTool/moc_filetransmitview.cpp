/****************************************************************************
** Meta object code from reading C++ file 'filetransmitview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/views/filetransmit/filetransmitview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filetransmitview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileTransmitView_t {
    QByteArrayData data[13];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileTransmitView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileTransmitView_t qt_meta_stringdata_FileTransmitView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FileTransmitView"
QT_MOC_LITERAL(1, 17, 11), // "receiveData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "array"
QT_MOC_LITERAL(4, 36, 14), // "cancelTransfer"
QT_MOC_LITERAL(5, 51, 6), // "logOut"
QT_MOC_LITERAL(6, 58, 6), // "string"
QT_MOC_LITERAL(7, 65, 5), // "color"
QT_MOC_LITERAL(8, 71, 19), // "browseButtonClicked"
QT_MOC_LITERAL(9, 91, 12), // "portSendData"
QT_MOC_LITERAL(10, 104, 8), // "sendFile"
QT_MOC_LITERAL(11, 113, 12), // "onTransFinsh"
QT_MOC_LITERAL(12, 126, 14) // "onTimeoutError"

    },
    "FileTransmitView\0receiveData\0\0array\0"
    "cancelTransfer\0logOut\0string\0color\0"
    "browseButtonClicked\0portSendData\0"
    "sendFile\0onTransFinsh\0onTimeoutError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileTransmitView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x0a /* Public */,
       5,    2,   63,    2, 0x0a /* Public */,
       5,    1,   68,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    6,    7,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileTransmitView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileTransmitView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->receiveData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->cancelTransfer(); break;
        case 2: _t->logOut((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 3: _t->logOut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->browseButtonClicked(); break;
        case 5: _t->portSendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->sendFile(); break;
        case 7: _t->onTransFinsh(); break;
        case 8: _t->onTimeoutError(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileTransmitView::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractView::staticMetaObject>(),
    qt_meta_stringdata_FileTransmitView.data,
    qt_meta_data_FileTransmitView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileTransmitView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileTransmitView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileTransmitView.stringdata0))
        return static_cast<void*>(this);
    return AbstractView::qt_metacast(_clname);
}

int FileTransmitView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
