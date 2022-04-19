#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T21:41:15
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Stage5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        selection.cpp \
    paciente.cpp \
    graph.cpp \
    qcustomplot.cpp \
    verdb.cpp

HEADERS += \
        selection.h \
    paciente.h \
    graph.h \
    qcustomplot.h \
    verdb.h

FORMS += \
        selection.ui \
    paciente.ui \
    graph.ui \
    verdb.ui
