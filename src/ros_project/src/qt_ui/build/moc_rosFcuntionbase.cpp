/****************************************************************************
** Meta object code from reading C++ file 'rosFcuntionbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rosFcuntionbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rosFcuntionbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RosFunBase_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RosFunBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RosFunBase_t qt_meta_stringdata_RosFunBase = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RosFunBase"
QT_MOC_LITERAL(1, 11, 18), // "signal_rosShutdown"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "signal_strMsg"
QT_MOC_LITERAL(4, 45, 6), // "pubMsg"
QT_MOC_LITERAL(5, 52, 3), // "msg"
QT_MOC_LITERAL(6, 56, 16), // "destination_site"
QT_MOC_LITERAL(7, 73, 10) // "notify_map"

    },
    "RosFunBase\0signal_rosShutdown\0\0"
    "signal_strMsg\0pubMsg\0msg\0destination_site\0"
    "notify_map"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RosFunBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   43,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void RosFunBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RosFunBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_rosShutdown(); break;
        case 1: _t->signal_strMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->pubMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->destination_site((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->notify_map((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RosFunBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RosFunBase::signal_rosShutdown)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RosFunBase::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RosFunBase::signal_strMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RosFunBase::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RosFunBase.data,
    qt_meta_data_RosFunBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RosFunBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RosFunBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RosFunBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RosFunBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RosFunBase::signal_rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RosFunBase::signal_strMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
