CPPFLAGS=$(shell sdl2-config --cflags) $(EXTRA_CPPFLAGS)
LDLIBS=$(shell sdl2-config --libs) -lGLEW $(EXTRA_LDLIBS)
<<<<<<< HEAD
EXTRA_LDLIBS?=-lGL -lglut
=======
EXTRA_LDLIBS?=-lGL -lglut -lGLU
>>>>>>> 5451fea (Menu expample for project.cpp)
all: project
clean:
	rm -f *.o project
.PHONY: all clean
