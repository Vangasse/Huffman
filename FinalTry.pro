TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    trainee.cpp \
    sourdough.cpp \
    node.cpp \
    link.cpp \
    filemanager.cpp \
    environmentalist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    trainee.h \
    sourdough.h \
    node.h \
    link.h \
    filemanager.h \
    environmentalist.h

