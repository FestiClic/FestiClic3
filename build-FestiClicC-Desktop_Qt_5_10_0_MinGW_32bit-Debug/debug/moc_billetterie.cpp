/****************************************************************************
** Meta object code from reading C++ file 'billetterie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FestiClicC/billetterie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'billetterie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Billetterie_t {
    QByteArrayData data[14];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Billetterie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Billetterie_t qt_meta_stringdata_Billetterie = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Billetterie"
QT_MOC_LITERAL(1, 12, 43), // "on_bCBoxRepresentations_curre..."
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 4), // "arg1"
QT_MOC_LITERAL(4, 62, 39), // "on_bCBoxSpectacteur_currentIn..."
QT_MOC_LITERAL(5, 102, 22), // "on_bBtnAjouter_clicked"
QT_MOC_LITERAL(6, 125, 33), // "on_bCBoxTarif_currentIndexCha..."
QT_MOC_LITERAL(7, 159, 22), // "on_bBtnSuivant_clicked"
QT_MOC_LITERAL(8, 182, 23), // "on_bBtnPaiement_clicked"
QT_MOC_LITERAL(9, 206, 22), // "on_bBtnQuitter_clicked"
QT_MOC_LITERAL(10, 229, 22), // "on_bBtnEspeces_clicked"
QT_MOC_LITERAL(11, 252, 21), // "on_bBtnCheque_clicked"
QT_MOC_LITERAL(12, 274, 25), // "on_bBtnChVacances_clicked"
QT_MOC_LITERAL(13, 300, 24) // "on_bBtnChCulture_clicked"

    },
    "Billetterie\0on_bCBoxRepresentations_currentIndexChanged\0"
    "\0arg1\0on_bCBoxSpectacteur_currentIndexChanged\0"
    "on_bBtnAjouter_clicked\0"
    "on_bCBoxTarif_currentIndexChanged\0"
    "on_bBtnSuivant_clicked\0on_bBtnPaiement_clicked\0"
    "on_bBtnQuitter_clicked\0on_bBtnEspeces_clicked\0"
    "on_bBtnCheque_clicked\0on_bBtnChVacances_clicked\0"
    "on_bBtnChCulture_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Billetterie[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    0,   75,    2, 0x08 /* Private */,
       6,    1,   76,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Billetterie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Billetterie *_t = static_cast<Billetterie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_bCBoxRepresentations_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_bCBoxSpectacteur_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_bBtnAjouter_clicked(); break;
        case 3: _t->on_bCBoxTarif_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_bBtnSuivant_clicked(); break;
        case 5: _t->on_bBtnPaiement_clicked(); break;
        case 6: _t->on_bBtnQuitter_clicked(); break;
        case 7: _t->on_bBtnEspeces_clicked(); break;
        case 8: _t->on_bBtnCheque_clicked(); break;
        case 9: _t->on_bBtnChVacances_clicked(); break;
        case 10: _t->on_bBtnChCulture_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Billetterie::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Billetterie.data,
      qt_meta_data_Billetterie,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Billetterie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Billetterie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Billetterie.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Billetterie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
