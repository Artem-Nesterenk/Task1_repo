TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lrt

SOURCES += \
        main.c \
        msg_ctrl.c \
        reciever.c \
        sender.c \
        vehicle.c
HEADERS += \
  defines.h \
  msg_ctrl.h \
  reciever.h \
  sender.h \
  vehicle.h

