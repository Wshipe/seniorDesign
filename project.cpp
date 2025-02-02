<<<<<<< HEAD
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {

  return 0;
=======
#include "config.h"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLsizei winWidth = 400, winHeight = 400;

GLfloat red = 1.0, green = 1.0, blue = 1.0;
GLenum renderingMode = GL_SMOOTH;

void init() {
  glClearColor(.6, .6, .6, 1);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 300, 0, 300);
}

void mainMenu (GLint renderingOption) {
  switch (renderingOption) {
    case 1: 
      renderingMode = GL_FLAT;
      break;
    case 2:
      renderingMode = GL_SMOOTH; 
      break;
  }
  glutPostRedisplay();
}

void colorSubMenu (GLint colorOption) {
  switch (colorOption) {
    case 1:
      red = 0; green = 0; blue = 1;
    break;
    case 2:
      red = 0; green = 1; blue = 0;
    break;
    case 3:
      red = 1; green = 1; blue = 1;
  }
  glutPostRedisplay();
}

void displayTriangle () {
  glClear(GL_COLOR_BUFFER_BIT);

  glShadeModel(renderingMode);
  glColor3f(red, green, blue);

  glBegin(GL_TRIANGLES);
  glVertex2i(280, 20);
  glVertex2i(160, 280);
  glColor3f(red, 0, 0);
  glVertex2i(20, 100);
  glEnd();

  glFlush();
}

void reshapeFcn (GLint newWidth, GLint newHeight) {
  glViewport(0, 0, newWidth, newHeight);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, GLfloat (newWidth), 0, GLfloat (newHeight));
  displayTriangle ();
  glFlush();
}

int main (int argc, char **argv) {
  GLint subMenu;

  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize (winWidth, winHeight);
  glutCreateWindow("Menu Example");

  init ();
  glutDisplayFunc(displayTriangle);

  subMenu = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Blue", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("White", 3);

  glutCreateMenu(mainMenu);
  glutAddMenuEntry("Solid-Color Fill", 1);
  glutAddMenuEntry("Color-Interpolation Fill", 2);
  glutAddSubMenu("Color", subMenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutReshapeFunc(reshapeFcn);

  glutMainLoop();
>>>>>>> 5451fea (Menu expample for project.cpp)
}
