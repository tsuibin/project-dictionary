/****************************************************************************
** Meta object code from reading C++ file 'dictionary.h'
**
** Created: Mon Sep 20 12:35:09 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dictionary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dictionary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dictionary[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      23,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   42,   11,   11, 0x0a,
      67,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     153,  148,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     218,  212,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dictionary[] = {
    "dictionary\0\0openHanw()\0dic_window_close()\0"
    "word\0insertWord(QString)\0"
    "on_handw_input_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_WordIput_textEdited(QString)\0item\0"
    "on_listWidget_itemClicked(QListWidgetItem*)\0"
    "timeout_slot()\0reply\0replyFinished(QNetworkReply*)\0"
};

const QMetaObject dictionary::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dictionary,
      qt_meta_data_dictionary, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dictionary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dictionary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dictionary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dictionary))
        return static_cast<void*>(const_cast< dictionary*>(this));
    return QWidget::qt_metacast(_clname);
}

int dictionary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openHanw(); break;
        case 1: dic_window_close(); break;
        case 2: insertWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_handw_input_clicked(); break;
        case 4: on_pushButton_clicked(); break;
        case 5: on_WordIput_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: timeout_slot(); break;
        case 8: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void dictionary::openHanw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void dictionary::dic_window_close()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
