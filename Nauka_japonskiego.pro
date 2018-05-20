TARGET = Nauka_japonskiego

QT = core gui

QMAKE_CXXFLAGS += -pedantic

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    gui.cpp

HEADERS += \
    gui.h

