/****************************************************************************
** Meta object code from reading C++ file 'imagineviewerwindow.h'
**
** Created: Tue Apr 30 13:16:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagineviewerwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagineviewerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImagineViewerWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   20,   20,   20, 0x08,
      74,   20,   20,   20, 0x08,
     106,  101,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,
     147,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImagineViewerWindow[] = {
    "ImagineViewerWindow\0\0imagen\0"
    "enviar_imagen(QImage)\0on_pushButton_clicked()\0"
    "on_actionAbrir_triggered()\0rect\0"
    "on_movie_updated(QRect)\0recibir_imagen()\0"
    "crear_conexiones()\0"
};

void ImagineViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImagineViewerWindow *_t = static_cast<ImagineViewerWindow *>(_o);
        switch (_id) {
        case 0: _t->enviar_imagen((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_actionAbrir_triggered(); break;
        case 3: _t->on_movie_updated((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 4: _t->recibir_imagen(); break;
        case 5: _t->crear_conexiones(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImagineViewerWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImagineViewerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImagineViewerWindow,
      qt_meta_data_ImagineViewerWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImagineViewerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImagineViewerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImagineViewerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImagineViewerWindow))
        return static_cast<void*>(const_cast< ImagineViewerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImagineViewerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ImagineViewerWindow::enviar_imagen(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
