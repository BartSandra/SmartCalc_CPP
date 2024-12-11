QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    form_2.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    ../model/credit_calc.cc \
    ../model/deposit_calc.cc \
    ../model/model.cc \
    ../controller/controller.cc

HEADERS += \
    form.h \
    form_2.h \
    mainwindow.h \
    qcustomplot.h \
    ../model/model.h \
    ../controller/controller.h

FORMS += \
    form.ui \
    form_2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
