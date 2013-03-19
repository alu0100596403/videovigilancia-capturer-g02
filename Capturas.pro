#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T12:41:50
#
#-------------------------------------------------
#lineas para lo que viene despues .

PROTOS = sensorsreport.proto
include(protobuf.pri)

#linea para deteccion de movimiento.
include(QtOpenCV.pri)

add_opencv_modules(core video imgproc, 2.4.4)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capturas
TEMPLATE = app


SOURCES += main.cpp\
        imagineviewerwindow.cpp \
    procesadora.cpp \
    cvmatandqimage.cpp

HEADERS  += \
    imagineviewerwindow.h \
    procesadora.h \
    cvmatandqimage.h

FORMS    += imagineviewerwindow.ui

OTHER_FILES += \
    opencv.pri \
    QtOpenCV.pri
