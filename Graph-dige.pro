#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T19:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph-dige
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/Parser.cpp \
    src/Graph.cpp

HEADERS  += mainwindow.h \
    include/Parser.h \
    include/Graph.h \
    include/Node.h \
    include/Graphic.h \
    src/graph.h

FORMS    += mainwindow.ui
