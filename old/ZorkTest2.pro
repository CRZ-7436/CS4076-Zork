TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        item.cpp

DISTFILES += \
    ZorkTest2.pro.user

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h \
    main.h
