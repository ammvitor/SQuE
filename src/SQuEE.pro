TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    xvg_parser.cpp

HEADERS += \
    xvg_parser.h

