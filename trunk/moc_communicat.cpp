/****************************************************************************
** Meta object code from reading C++ file 'communicat.h'
**
** Created: Tue Nov 9 19:49:18 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "communicat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communicat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_communicat[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      78,   11,   11,   11, 0x0a,
     105,   11,   11,   11, 0x0a,
     121,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_communicat[] = {
    "communicat\0\0sendWord(QString)\0"
    "set_windowColor(QColor)\0set_dictionary_wid(int)\0"
    "set_dictionary_height(int)\0set_all_tm(int)\0"
    "sys_init()\0"
};

const QMetaObject communicat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_communicat,
      qt_meta_data_communicat, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &communicat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *communicat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *communicat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_communicat))
        return static_cast<void*>(const_cast< communicat*>(this));
    return QObject::qt_metacast(_clname);
}

int communicat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: set_windowColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: set_dictionary_wid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: set_dictionary_height((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: set_all_tm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: sys_init(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void communicat::sendWord(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
