/****************************************************************************
** Meta object code from reading C++ file 'clients.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FestiClicC/clients.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Clients_t {
    QByteArrayData data[9];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Clients_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Clients_t qt_meta_stringdata_Clients = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Clients"
QT_MOC_LITERAL(1, 8, 24), // "on_cltBtnQuitter_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_cltBtnAjouter_clicked"
QT_MOC_LITERAL(4, 59, 25), // "on_cltBtnModifier_clicked"
QT_MOC_LITERAL(5, 85, 26), // "on_cltBtnSupprimer_clicked"
QT_MOC_LITERAL(6, 112, 20), // "on_cltTabV_activated"
QT_MOC_LITERAL(7, 133, 5), // "index"
QT_MOC_LITERAL(8, 139, 28) // "on_cltBtnViderChamps_clicked"

    },
    "Clients\0on_cltBtnQuitter_clicked\0\0"
    "on_cltBtnAjouter_clicked\0"
    "on_cltBtnModifier_clicked\0"
    "on_cltBtnSupprimer_clicked\0"
    "on_cltTabV_activated\0index\0"
    "on_cltBtnViderChamps_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Clients[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,

       0        // eod
};

void Clients::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Clients *_t = static_cast<Clients *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cltBtnQuitter_clicked(); break;
        case 1: _t->on_cltBtnAjouter_clicked(); break;
        case 2: _t->on_cltBtnModifier_clicked(); break;
        case 3: _t->on_cltBtnSupprimer_clicked(); break;
        case 4: _t->on_cltTabV_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_cltBtnViderChamps_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Clients::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Clients.data,
      qt_meta_data_Clients,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Clients::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Clients::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Clients.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Clients::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
