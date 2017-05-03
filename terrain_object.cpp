#include "terrain_object.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace std;

/* Terrain Object Class Definitions */

TerrainObject::TerrainObject() { }
TerrainObject::~TerrainObject() { }

int TerrainObject::get_x_coord() const { return x_coord; }
int TerrainObject::get_y_coord() const { return y_coord; }
double TerrainObject::getTerrainSpeed() const { return terrain_speed; }
GameObject::color TerrainObject::getColor() { return fill; }
terrain TerrainObject::getTerrainType() const { return terrain_type; }

void TerrainObject::set_x_coord(int x) {
    if (x >= 0) {
        x_coord = x;
    } else {
        cout << "error: negative value for x" << endl;
        x_coord = 1;
    }
}

void TerrainObject::set_y_coord(int y) {
    if (y >= 0) {
        y_coord = y;
    } else {
        cout << "error: negative value for y" << endl;
        y_coord = 1;
    }
}

void TerrainObject::setColor(double r, double g, double b) {
    if (r >=0 && g >=0 && b >= 0) {
        fill = {r,g,b};
    } else {
        cout << "error: negative value for a color value" << endl;
        fill = {0,0,0};
    }
}

/* End of Terrain Object Class Definitions */


/* Grass Object Class Definitions */

Grass::Grass(int x, int y) {
    set_x_coord(x);
    set_y_coord(y);
    setColor(0,200.0/255,0);
	terrain_type = grass;
}
void Grass::draw() const {
	glBegin(GL_QUADS);
	glColor3f(fill.red, fill.green, fill.blue);
	glVertex2i(x_coord*side_length, y_coord*side_length);
	glVertex2i((x_coord*side_length) + side_length, y_coord*side_length);
	glVertex2i((x_coord*side_length) + side_length, (y_coord*side_length) + side_length);
	glVertex2i(x_coord*side_length, (y_coord*side_length) + side_length);
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(.2,.5,.2);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+2);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+2);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+4);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+4);
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,150.0/255,0);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(25.0/255,90.0/255,10.0/255);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+18);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+18);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+20);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,195.0/255,5.0/255);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+14);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+14);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(20.0/255,180.0/255,25.0/255);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+4);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+4);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+6);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(10.0/255,220.0/255,25.0/255);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+12, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(22.0/255,200.0/255,15.0/255);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+1);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+1);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.7,0);
    glVertex2i(x_coord*side_length+1, y_coord*side_length+8);
    glVertex2i(x_coord*side_length+3, y_coord*side_length+8);
    glVertex2i(x_coord*side_length+3, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+1, y_coord*side_length+10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.6,0);
    glVertex2i(x_coord*side_length+5, y_coord*side_length+6);
    glVertex2i(x_coord*side_length+7, y_coord*side_length+6);
    glVertex2i(x_coord*side_length+7, y_coord*side_length+8);
    glVertex2i(x_coord*side_length+5, y_coord*side_length+8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.5,0);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+15);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.7,0);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+10);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.5,0);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+18);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.65,0);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+0);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+0);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+2);
    glVertex2i(x_coord*side_length+14, y_coord*side_length+2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.5,0);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+5);
    glVertex2i(x_coord*side_length+16, y_coord*side_length+5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,.7,0);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+15);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+15);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0,.4,0);
    glVertex2i(x_coord*side_length+5, y_coord*side_length+0);
    glVertex2i(x_coord*side_length+7, y_coord*side_length+0);
    glVertex2i(x_coord*side_length+7, y_coord*side_length+2);
    glVertex2i(x_coord*side_length+5, y_coord*side_length+2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.3,.7,.3);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+4, y_coord*side_length+18);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.2,.9,.2);
    glVertex2i(x_coord*side_length+15, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+17, y_coord*side_length+16);
    glVertex2i(x_coord*side_length+17, y_coord*side_length+18);
    glVertex2i(x_coord*side_length+15, y_coord*side_length+18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.2,.9,.2);
    glVertex2i(x_coord*side_length+17, y_coord*side_length+6);
    glVertex2i(x_coord*side_length+19, y_coord*side_length+6);
    glVertex2i(x_coord*side_length+19, y_coord*side_length+8);
    glVertex2i(x_coord*side_length+17, y_coord*side_length+8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.2,.8,.3);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+7);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+7);
    glVertex2i(x_coord*side_length+11, y_coord*side_length+9);
    glVertex2i(x_coord*side_length+9, y_coord*side_length+9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.4,.1);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+13);
    glVertex2i(x_coord*side_length+10, y_coord*side_length+15);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.2,.8,.2);
    glVertex2i(x_coord*side_length+0, y_coord*side_length+5);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+5);
    glVertex2i(x_coord*side_length+2, y_coord*side_length+7);
    glVertex2i(x_coord*side_length+0, y_coord*side_length+7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.15,.7,.25);
    glVertex2i(x_coord*side_length+1, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+3, y_coord*side_length+12);
    glVertex2i(x_coord*side_length+3, y_coord*side_length+14);
    glVertex2i(x_coord*side_length+1, y_coord*side_length+14);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.7,.1);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+1);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+1);
    glVertex2i(x_coord*side_length+20, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+18, y_coord*side_length+3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+3);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+5);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.6,0);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+9);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+9);
    glVertex2i(x_coord*side_length+8, y_coord*side_length+11);
    glVertex2i(x_coord*side_length+6, y_coord*side_length+11);
    glEnd();
}


/* End of Grass Object Class Definitions */


/* Water Object Class Definitions */

Water::Water(int x, int y) {
    set_x_coord(x);
    set_y_coord(y);
    setColor(0,0,255);
	terrain_type = water;
}
void Water::draw() const {
	glBegin(GL_QUADS);
	glColor3f(fill.red, fill.green, fill.blue);
	glVertex2i(x_coord*side_length, y_coord*side_length);
	glVertex2i((x_coord*side_length) + side_length, y_coord*side_length);
	glVertex2i((x_coord*side_length) + side_length, (y_coord*side_length) + side_length);
	glVertex2i(x_coord*side_length, (y_coord*side_length) + side_length);
	glEnd();
}

/* End of Water Object Class Definitions */
