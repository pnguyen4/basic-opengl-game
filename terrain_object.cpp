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
    setColor(0,255,0);
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
