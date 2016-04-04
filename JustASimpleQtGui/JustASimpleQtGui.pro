QT += core gui opengl
QT += widgets

TEMPLATE = app

SOURCES += src/*.cpp

FORMS += \
    mainwindow.ui

CONFIG +=c++11

HEADERS += include/*.h

OBJECTS_DIR+=obj

LIBS += -L/$(HOME)/NGL/lib -l NGL
INCLUDEPATH += $$(HOME)/NGL/include/
INCLUDEPATH +=$$PWD/include

OTHER_FILES+=$$PWD/shaders/*
