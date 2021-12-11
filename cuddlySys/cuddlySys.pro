#-------------------------------------------------
#
# Project created by QtCreator 2021-04-03T17:35:00
#
#-------------------------------------------------

QT       += core gui sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuddlySys
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    database.cpp \
        main.cpp \
        entry.cpp \
    petowner.cpp \
    shelterownermain.cpp \
    managepet.cpp \
    registrationmain.cpp \
    petownerpref.cpp \
    usermanager.cpp \
    matchmaking.cpp \
    history.cpp \
    adoptions.cpp \
    updateinfopetowner.cpp \
    updateinfoshelter.cpp \
    petmanager.cpp \
    searchwin.cpp \
    manageusers.cpp \
    viewrequests.cpp \
    petprofile.cpp \
    viewuserprofile.cpp \
    viewpetreq.cpp \
    computedist.cpp \
    adminadduser.cpp \
    adminupdateshelter.cpp \
    adminupdatepetowner.cpp \
    addpet.cpp \
    shelterownerstats.cpp \
    updatepetprofile.cpp \
    updatepet.cpp

HEADERS += \
    database.h \
        entry.h \
    petowner.h \
    shelterownermain.h \
    managepet.h \
    registrationmain.h \
    petownerpref.h \
    usermanager.h \
    header.h \
    matchmaking.h \
    history.h \
    adoptions.h \
    updateinfopetowner.h \
    updateinfoshelter.h \
    petmanager.h \
    searchwin.h \
    manageusers.h \
    viewrequests.h \
    petprofile.h \
    viewuserprofile.h \
    viewpetreq.h \
    computedist.h \
    adminadduser.h \
    adminupdateshelter.h \
    adminupdatepetowner.h \
    addpet.h \
    shelterownerstats.h \
    updatepetprofile.h \
    updatepet.h

FORMS += \
        entry.ui \
    petowner.ui \
    shelterownermain.ui \
    managepet.ui \
    registrationmain.ui \
    petownerpref.ui \
    matchmaking.ui \
    history.ui \
    adoptions.ui \
    updateinfopetowner.ui \
    updateinfoshelter.ui \
    searchwin.ui \
    manageusers.ui \
    viewrequests.ui \
    petprofile.ui \
    viewuserprofile.ui \
    viewpetreq.ui \
    adminadduser.ui \
    adminupdateshelter.ui \
    adminupdatepetowner.ui \
    addpet.ui \
    shelterownerstats.ui \
    updatepetprofile.ui \
    updatepet.ui
