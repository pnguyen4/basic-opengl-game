#ifndef graphics_h
#define graphics_h

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifdef __linux__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

void init(void);

void display(void);

void reshape(int w, int h);

void refresh(void);

void kbd(unsigned char key, int x, int y);

void cursor(int x, int y);

void drag(int x, int y);

void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);

#endif
