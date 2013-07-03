#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T13:18:49
#
#-------------------------------------------------

QT       += core
QT       += network

QT       += gui



PROTOS = Mensaje.proto
include(protobuf.pri)


TARGET = capturaservidor
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    servidor.cpp

HEADERS += \
    servidor.h \
    Mensaje.pb.h

OTHER_FILES += \
    Mensaje.proto

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += protobuf
