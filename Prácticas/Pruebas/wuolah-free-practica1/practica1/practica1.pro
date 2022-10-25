HEADERS = \ 
    cubo.h \
    O3D.h \
    O3DS.h \
    vertex.h \
    tetraedro.h

SOURCES = \
    practica1.cc \
    cubo.cpp \
    O3D.cpp \
    O3DS.cpp \
    tetraedro.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

