#############################################################################
# Makefile for building: dictionary
# Generated by qmake (2.01a) (Qt 4.7.0) on: Tue Nov 9 19:23:28 2010
# Project:  dictionary.pro
# Template: app
# Command: /home/tsuibin/qtsdk-2010.05/qt/bin/qmake -spec ../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile dictionary.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_SQL_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../qtsdk-2010.05/qt/mkspecs/linux-g++ -I. -I../../qtsdk-2010.05/qt/include/QtCore -I../../qtsdk-2010.05/qt/include/QtNetwork -I../../qtsdk-2010.05/qt/include/QtGui -I../../qtsdk-2010.05/qt/include/QtXml -I../../qtsdk-2010.05/qt/include/QtSql -I../../qtsdk-2010.05/qt/include/QtWebKit -I../../qtsdk-2010.05/qt/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/tsuibin/qtsdk-2010.05/qt/lib
LIBS          = $(SUBLIBS)  -L/home/tsuibin/qtsdk-2010.05/qt/lib -L/home/tsuibin/source/project-dictionary -lzinnia -lQtWebKit -lQtSql -L/home/tsuibin/qtsdk-2010.05/qt/lib -lQtXml -lQtGui -L/usr/X11R6/lib -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/tsuibin/qtsdk-2010.05/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		dictionary.cpp \
		hand_wdialog.cpp \
		communicat.cpp \
		set_dialog.cpp moc_dictionary.cpp \
		moc_hand_wdialog.cpp \
		moc_communicat.cpp \
		moc_set_dialog.cpp
OBJECTS       = main.o \
		dictionary.o \
		hand_wdialog.o \
		communicat.o \
		set_dialog.o \
		moc_dictionary.o \
		moc_hand_wdialog.o \
		moc_communicat.o \
		moc_set_dialog.o
DIST          = ../../qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		../../qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		../../qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		../../qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/debug.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
		dictionary.pro
QMAKE_TARGET  = dictionary
DESTDIR       = 
TARGET        = dictionary

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_dictionary.h ui_hand_wdialog.h ui_set_dialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: dictionary.pro  ../../qtsdk-2010.05/qt/mkspecs/linux-g++/qmake.conf ../../qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		../../qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		../../qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		../../qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/debug.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtWebKit.prl \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtSql.prl \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtCore.prl \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtXml.prl \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtGui.prl \
		/home/tsuibin/qtsdk-2010.05/qt/lib/libQtNetwork.prl
	$(QMAKE) -spec ../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile dictionary.pro
../../qtsdk-2010.05/qt/mkspecs/common/g++.conf:
../../qtsdk-2010.05/qt/mkspecs/common/unix.conf:
../../qtsdk-2010.05/qt/mkspecs/common/linux.conf:
../../qtsdk-2010.05/qt/mkspecs/qconfig.pri:
../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri:
../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf:
../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf:
../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf:
../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf:
../../qtsdk-2010.05/qt/mkspecs/features/debug.prf:
../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf:
../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf:
../../qtsdk-2010.05/qt/mkspecs/features/qt.prf:
../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf:
../../qtsdk-2010.05/qt/mkspecs/features/moc.prf:
../../qtsdk-2010.05/qt/mkspecs/features/resources.prf:
../../qtsdk-2010.05/qt/mkspecs/features/uic.prf:
../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf:
../../qtsdk-2010.05/qt/mkspecs/features/lex.prf:
../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtWebKit.prl:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtSql.prl:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtCore.prl:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtXml.prl:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtGui.prl:
/home/tsuibin/qtsdk-2010.05/qt/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile dictionary.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/dictionary1.0.0 || $(MKDIR) .tmp/dictionary1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/dictionary1.0.0/ && $(COPY_FILE) --parents dictionary.h hand_wdialog.h communicat.h set_dialog.h .tmp/dictionary1.0.0/ && $(COPY_FILE) --parents main.cpp dictionary.cpp hand_wdialog.cpp communicat.cpp set_dialog.cpp .tmp/dictionary1.0.0/ && $(COPY_FILE) --parents dictionary.ui hand_wdialog.ui set_dialog.ui .tmp/dictionary1.0.0/ && (cd `dirname .tmp/dictionary1.0.0` && $(TAR) dictionary1.0.0.tar dictionary1.0.0 && $(COMPRESS) dictionary1.0.0.tar) && $(MOVE) `dirname .tmp/dictionary1.0.0`/dictionary1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/dictionary1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_dictionary.cpp moc_hand_wdialog.cpp moc_communicat.cpp moc_set_dialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_dictionary.cpp moc_hand_wdialog.cpp moc_communicat.cpp moc_set_dialog.cpp
moc_dictionary.cpp: dictionary.h
	/home/tsuibin/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) dictionary.h -o moc_dictionary.cpp

moc_hand_wdialog.cpp: zinnia.h \
		hand_wdialog.h
	/home/tsuibin/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) hand_wdialog.h -o moc_hand_wdialog.cpp

moc_communicat.cpp: dictionary.h \
		hand_wdialog.h \
		zinnia.h \
		set_dialog.h \
		communicat.h
	/home/tsuibin/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) communicat.h -o moc_communicat.cpp

moc_set_dialog.cpp: set_dialog.h
	/home/tsuibin/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) set_dialog.h -o moc_set_dialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_dictionary.h ui_hand_wdialog.h ui_set_dialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_dictionary.h ui_hand_wdialog.h ui_set_dialog.h
ui_dictionary.h: dictionary.ui
	/home/tsuibin/qtsdk-2010.05/qt/bin/uic dictionary.ui -o ui_dictionary.h

ui_hand_wdialog.h: hand_wdialog.ui
	/home/tsuibin/qtsdk-2010.05/qt/bin/uic hand_wdialog.ui -o ui_hand_wdialog.h

ui_set_dialog.h: set_dialog.ui
	/home/tsuibin/qtsdk-2010.05/qt/bin/uic set_dialog.ui -o ui_set_dialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp dictionary.h \
		hand_wdialog.h \
		zinnia.h \
		communicat.h \
		set_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

dictionary.o: dictionary.cpp dictionary.h \
		ui_dictionary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dictionary.o dictionary.cpp

hand_wdialog.o: hand_wdialog.cpp zinnia.h \
		hand_wdialog.h \
		ui_hand_wdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hand_wdialog.o hand_wdialog.cpp

communicat.o: communicat.cpp communicat.h \
		dictionary.h \
		hand_wdialog.h \
		zinnia.h \
		set_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o communicat.o communicat.cpp

set_dialog.o: set_dialog.cpp set_dialog.h \
		ui_set_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o set_dialog.o set_dialog.cpp

moc_dictionary.o: moc_dictionary.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dictionary.o moc_dictionary.cpp

moc_hand_wdialog.o: moc_hand_wdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_hand_wdialog.o moc_hand_wdialog.cpp

moc_communicat.o: moc_communicat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_communicat.o moc_communicat.cpp

moc_set_dialog.o: moc_set_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_set_dialog.o moc_set_dialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

