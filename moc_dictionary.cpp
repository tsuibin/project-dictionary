/****************************************************************************
** Meta object code from reading C++ file 'dictionary.h'
**
** Created: Thu Sep 16 10:09:49 2010
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
     102,   97,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     167,  161,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dictionary[] = {
    "dictionary\0\0on_WebSearchButton_clicked()\0"
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
    if (!strcmp(_clname, "QXmlDefaultHandler"))
        return static_cast< QXmlDefaultHandler*>(const_cast< dictionary*>(this));
    return QWidget::qt_metacast(_clname);
}

int dictionary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_WebSearchButton_clicked(); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_WordIput_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: timeout_slot(); break;
        case 5: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
