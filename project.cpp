#include "config.h"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat xO = 100.0, yO = 50.0, zO = 50.0; // Viewing-coordinate origin
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Look-at point
GLfloat Vx = 0, Vy = 1.0, Vz = 0.0; // View-up Vector

GLfloat xwMin = -40.0, xwMax = 40.0, ywMin = -60.0, ywMax = 60.0;
GLfloat dnear = 25.0, dfar = 125.0;

GLsizei winWidth = 600, winHeight = 600;
GLfloat red = 1.0, green = 1.0, blue = 1.0;
GLenum renderingMode = GL_SMOOTH;

void init() {
  glClearColor(red, green, blue, 0);

  glMatrixMode(GL_MODELVIEW);
  gluLookAt(xO, yO, zO, xref, yref, zref, Vx, Vy, Vz);

  glMatrixMode(GL_PROJECTION);
  glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);

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
      red = 1; green = 0; blue = 0;
    break;
    case 4:
      red = 0; green = 0; blue = 0;
  }
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Set parameters for a square fill area
  glShadeModel(renderingMode);
  glColor3f(red, green, blue);
  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE); // wire-frame back face
  glBegin(GL_QUADS);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(100.0, 0.0, 0.0);
  glVertex3d(100.0, 100.0, 0.0);
  glVertex3d(0.0, 100.0, 0.0);
  glEnd();

  glFlush();
}

void reshapeFcn (GLint newWidth, GLint newHeight) {
  glViewport(0, 0, newWidth, newHeight);

  winWidth = newWidth;
  winHeight = newHeight;
}

int main (int argc, char **argv) {
  GLint subMenu;

  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize (winWidth, winHeight);
  glutCreateWindow("Menu Example");

  init ();
  glutDisplayFunc(display);

  subMenu = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Blue", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("red", 3);
    glutAddMenuEntry("black", 4);

  glutCreateMenu(mainMenu);
  glutAddMenuEntry("Solid-Color Fill", 1);
  glutAddMenuEntry("Color-Interpolation Fill", 2);
  glutAddSubMenu("Color", subMenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutReshapeFunc(reshapeFcn);
  glutMainLoop();
}
