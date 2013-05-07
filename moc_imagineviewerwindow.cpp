/****************************************************************************
** Meta object code from reading C++ file 'imagineviewerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagineviewerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagineviewerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImagineViewerWindow_t {
    QByteArrayData data[14];
    char stringdata[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ImagineViewerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ImagineViewerWindow_t qt_meta_stringdata_ImagineViewerWindow = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 6),
QT_MOC_LITERAL(4, 42, 21),
QT_MOC_LITERAL(5, 64, 24),
QT_MOC_LITERAL(6, 89, 16),
QT_MOC_LITERAL(7, 106, 4),
QT_MOC_LITERAL(8, 111, 14),
QT_MOC_LITERAL(9, 126, 14),
QT_MOC_LITERAL(10, 141, 18),
QT_MOC_LITERAL(11, 160, 5),
QT_MOC_LITERAL(12, 166, 28),
QT_MOC_LITERAL(13, 195, 11)
    },
    "ImagineViewerWindow\0enviar_imagen\0\0"
    "imagen\0on_pushButton_clicked\0"
    "on_actionAbrir_triggered\0on_movie_updated\0"
    "rect\0recibir_imagen\0QVector<QRect>\0"
    "vector_rectangulos\0ERROR\0"
    "QAbstractSocket::SocketError\0socketError\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImagineViewerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08,
       5,    0,   48,    2, 0x08,
       6,    1,   49,    2, 0x08,
       8,    2,   52,    2, 0x08,
      11,    1,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,    7,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 9,    3,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void ImagineViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImagineViewerWindow *_t = static_cast<ImagineViewerWindow *>(_o);
        switch (_id) {
        case 0: _t->enviar_imagen((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_actionAbrir_triggered(); break;
        case 3: _t->on_movie_updated((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 4: _t->recibir_imagen((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QVector<QRect>(*)>(_a[2]))); break;
        case 5: _t->ERROR((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QRect> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImagineViewerWindow::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImagineViewerWindow::enviar_imagen)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ImagineViewerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImagineViewerWindow.data,
      qt_meta_data_ImagineViewerWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImagineViewerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImagineViewerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImagineViewerWindow.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
