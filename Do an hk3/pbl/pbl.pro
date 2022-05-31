QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QT += sql
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    array.cpp \
    chucvu.cpp \
    date.cpp \
    luong.cpp \
    main.cpp \
    mainwindow.cpp \
    nhanvien.cpp \
    phucap.cpp \
    thuclinh.cpp

HEADERS += \
    ../../Máy tính/oop doan/DOANPBL/luong.h \
    ../../Máy tính/oop doan/DOANPBL/luong.h \
    array.h \
    chucvu.h \
    date.h \
    luong.h \
    mainwindow.h \
    nhanvien.h \
    phucap.h \
    thuclinh.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
