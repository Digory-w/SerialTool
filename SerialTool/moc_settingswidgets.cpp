/****************************************************************************
** Meta object code from reading C++ file 'settingswidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/settings/settingswidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AbstractSettingsWidget_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractSettingsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractSettingsWidget_t qt_meta_stringdata_AbstractSettingsWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AbstractSettingsWidget"
QT_MOC_LITERAL(1, 23, 12), // "mutexChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "mutex"
QT_MOC_LITERAL(4, 43, 4), // "list"
QT_MOC_LITERAL(5, 48, 14), // "setMutexStatus"
QT_MOC_LITERAL(6, 63, 6) // "status"

    },
    "AbstractSettingsWidget\0mutexChanged\0"
    "\0mutex\0list\0setMutexStatus\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractSettingsWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QStringList,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    6,

       0        // eod
};

void AbstractSettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractSettingsWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mutexChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->setMutexStatus((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AbstractSettingsWidget::*)(bool , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractSettingsWidget::mutexChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AbstractSettingsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AbstractSettingsWidget.data,
    qt_meta_data_AbstractSettingsWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AbstractSettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractSettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractSettingsWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AbstractSettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AbstractSettingsWidget::mutexChanged(bool _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SettingsCheckBox_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsCheckBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsCheckBox_t qt_meta_stringdata_SettingsCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SettingsCheckBox"
QT_MOC_LITERAL(1, 17, 20), // "onCheckStatusChanged"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "SettingsCheckBox\0onCheckStatusChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsCheckBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SettingsCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsCheckBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCheckStatusChanged(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SettingsCheckBox::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractSettingsWidget::staticMetaObject>(),
    qt_meta_stringdata_SettingsCheckBox.data,
    qt_meta_data_SettingsCheckBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsCheckBox.stringdata0))
        return static_cast<void*>(this);
    return AbstractSettingsWidget::qt_metacast(_clname);
}

int SettingsCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractSettingsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SettingsFontSelect_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsFontSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsFontSelect_t qt_meta_stringdata_SettingsFontSelect = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SettingsFontSelect"
QT_MOC_LITERAL(1, 19, 10), // "fontDialog"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "SettingsFontSelect\0fontDialog\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsFontSelect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SettingsFontSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsFontSelect *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fontDialog(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SettingsFontSelect::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractSettingsWidget::staticMetaObject>(),
    qt_meta_stringdata_SettingsFontSelect.data,
    qt_meta_data_SettingsFontSelect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsFontSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsFontSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsFontSelect.stringdata0))
        return static_cast<void*>(this);
    return AbstractSettingsWidget::qt_metacast(_clname);
}

int SettingsFontSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractSettingsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SettingsFontFamily_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsFontFamily_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsFontFamily_t qt_meta_stringdata_SettingsFontFamily = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SettingsFontFamily"
QT_MOC_LITERAL(1, 19, 10), // "fontDialog"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "SettingsFontFamily\0fontDialog\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsFontFamily[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SettingsFontFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsFontFamily *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fontDialog(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SettingsFontFamily::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractSettingsWidget::staticMetaObject>(),
    qt_meta_stringdata_SettingsFontFamily.data,
    qt_meta_data_SettingsFontFamily,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsFontFamily::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsFontFamily::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsFontFamily.stringdata0))
        return static_cast<void*>(this);
    return AbstractSettingsWidget::qt_metacast(_clname);
}

int SettingsFontFamily::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractSettingsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
