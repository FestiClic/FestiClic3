/****************************************************************************
** Meta object code from reading C++ file 'spectacles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FestiClicC/spectacles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectacles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Spectacles_t {
    QByteArrayData data[11];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spectacles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spectacles_t qt_meta_stringdata_Spectacles = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Spectacles"
QT_MOC_LITERAL(1, 11, 22), // "on_sBtnQuitter_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "on_sBtnAjouter_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_sBtnModifier_clicked"
QT_MOC_LITERAL(5, 82, 39), // "on_sCBoxIdSpectacle_currentIn..."
QT_MOC_LITERAL(6, 122, 4), // "arg1"
QT_MOC_LITERAL(7, 127, 24), // "on_sBtnSupprimer_clicked"
QT_MOC_LITERAL(8, 152, 18), // "on_sTabV_activated"
QT_MOC_LITERAL(9, 171, 5), // "index"
QT_MOC_LITERAL(10, 177, 26) // "on_sBtnViderChamps_clicked"

    },
    "Spectacles\0on_sBtnQuitter_clicked\0\0"
    "on_sBtnAjouter_clicked\0on_sBtnModifier_clicked\0"
    "on_sCBoxIdSpectacle_currentIndexChanged\0"
    "arg1\0on_sBtnSupprimer_clicked\0"
    "on_sTabV_activated\0index\0"
    "on_sBtnViderChamps_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spectacles[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,

       0        // eod
};

void Spectacles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spectacles *_t = static_cast<Spectacles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sBtnQuitter_clicked(); break;
        case 1: _t->on_sBtnAjouter_clicked(); break;
        case 2: _t->on_sBtnModifier_clicked(); break;
        case 3: _t->on_sCBoxIdSpectacle_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_sBtnSupprimer_clicked(); break;
        case 5: _t->on_sTabV_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_sBtnViderChamps_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Spectacles::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Spectacles.data,
      qt_meta_data_Spectacles,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Spectacles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spectacles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Spectacles.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Spectacles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
