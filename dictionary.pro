#-------------------------------------------------
#
# Project created by QtCreator 2010-09-02T08:42:05
#
#-------------------------------------------------

QT       += core gui sql network xml

TARGET = dictionary
TEMPLATE = app
LIBS += -lzinnia

SOURCES += main.cpp\
        dictionary.cpp \
    hand_wdialog.cpp

HEADERS  += dictionary.h \
    hand_wdialog.h

FORMS    += dictionary.ui \
    hand_wdialog.ui
