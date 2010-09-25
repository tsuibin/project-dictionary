#-------------------------------------------------
#
# Project created by QtCreator 2010-09-02T08:42:05
#
#-------------------------------------------------

QT       += core gui sql network xml QT3_SUPPORT

TARGET = dictionary
TEMPLATE = app
LIBS += -lzinnia

SOURCES += main.cpp\
        dictionary.cpp \
    hand_wdialog.cpp \
    communicat.cpp \
    addic_thread.cpp

HEADERS  += dictionary.h \
    hand_wdialog.h \
    communicat.h \
    addic_thread.h

FORMS    += dictionary.ui \
    hand_wdialog.ui
