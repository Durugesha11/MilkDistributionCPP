TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
DESTDIR +=$$PWD

SOURCES += \
        MilkDistributor.cpp \
        address.cpp \
        customer.cpp \
        customerdetailsenum.cpp \
        gcs.cpp \
        main.cpp \
        milk.cpp \
        milkdistributioninterface.cpp

HEADERS += \
    MilkDistributor.h \
    address.h \
    customer.h \
    customerdetailsenum.h \
    gcs.h \
    milk.h \
    milkdistributioninterface.h

DEFINES+=MYDEBUG_STATUS=1
