/****************************************************************************
** Meta object code from reading C++ file 'GUIExampleSpawnWidget.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUIExampleSpawnWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIExampleSpawnWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gazebo__GUIExampleSpawnWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x09,
      55,   30,   30,   30, 0x09,
      81,   30,   30,   30, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_gazebo__GUIExampleSpawnWidget[] = {
    "gazebo::GUIExampleSpawnWidget\0\0"
    "OnButton_btnMoveRobot()\0"
    "OnButton_btnSpawnSphere()\0OnButton_btnTest()\0"
};

void gazebo::GUIExampleSpawnWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GUIExampleSpawnWidget *_t = static_cast<GUIExampleSpawnWidget *>(_o);
        switch (_id) {
        case 0: _t->OnButton_btnMoveRobot(); break;
        case 1: _t->OnButton_btnSpawnSphere(); break;
        case 2: _t->OnButton_btnTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData gazebo::GUIExampleSpawnWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gazebo::GUIExampleSpawnWidget::staticMetaObject = {
    { &GUIPlugin::staticMetaObject, qt_meta_stringdata_gazebo__GUIExampleSpawnWidget,
      qt_meta_data_gazebo__GUIExampleSpawnWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gazebo::GUIExampleSpawnWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gazebo::GUIExampleSpawnWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gazebo::GUIExampleSpawnWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gazebo__GUIExampleSpawnWidget))
        return static_cast<void*>(const_cast< GUIExampleSpawnWidget*>(this));
    return GUIPlugin::qt_metacast(_clname);
}

int gazebo::GUIExampleSpawnWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GUIPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
