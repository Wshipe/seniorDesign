## Linux Makefile for Freeglut 
CPPFLAGS=$(shell sdl2-config --cflags) $(EXTRA_CPPFLAGS)
LDLIBS=$(shell sdl2-config --libs) -lGLEW $(EXTRA_LDLIBS)
EXTRA_LDLIBS?=-lGL -lglut -lGLU
all: project ## Main file
clean:
	rm -f *.o project
.PHONY: all clean
