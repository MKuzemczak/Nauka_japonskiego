TARGET = Nauka_japonskiego

QT = core gui

QMAKE_CXXFLAGS += -pedantic

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    gui.cpp \
    scribblearea.cpp \
    dataloader.cpp \
    answercounter.cpp \
    numberset.cpp \
    lineedit.cpp

HEADERS += \
    gui.h \
    scribblearea.h \
    dataloader.h \
    answercounter.h \
    randutils.hpp \
    alphabetamount.h \
    numberset.h \
    lineedit.h

