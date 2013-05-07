#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T12:41:50
#
#-------------------------------------------------
#Para poder usa QNetwork
QT += network

#lineas para lo que viene despues .

PROTOS = Mensaje.proto
include(protobuf.pri)

#linea para deteccion de movimiento.
include(QtOpenCV.pri)

add_opencv_modules(core video imgproc)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capturas
TEMPLATE = app


SOURCES += main.cpp\
        imagineviewerwindow.cpp \
    procesadora.cpp

HEADERS  += \
    imagineviewerwindow.h \
    procesadora.h \
     cvmatandqimage \
     cvmatandqimage \
    servidor.h

FORMS    += imagineviewerwindow.ui

OTHER_FILES += \
    opencv.pri \
    QtOpenCV.pri \
    Mensaje.proto

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += protobuf
