#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T18:32:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = OD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../qcustomplot/qcustomplot.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialog4.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    ../qcustomplot/qcustomplot.h \
    dialog1.h \
    dialog2.h \
    dialog3.h \
    dialog4.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui \
    dialog4.ui
