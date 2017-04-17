#include "terrain_object.hpp"
using namespace std;

/* Terrain Object Class Definitions */

TerrainObject::TerrainObject() { }
TerrainObject::~TerrainObject() { }

int TerrainObject::get_x_coord() const { return x_coord; }
int TerrainObject::get_y_coord() const { return y_coord; }
double TerrainObject::getTerrainSpeed() const { return terrain_speed; }
color TerrainObject::getColor() { return fill; }

void TerrainObject::set_x_coord(int x) {
    x_coord = x;
    /* todo: check for valid input */
}

void TerrainObject::set_y_coord(int y) {
    y_coord = y;
    /* todo: check for valid input */
}

void TerrainObject::setColor(double r, double b, double g) {
    fill = {r,g,b};
}

/* End of Terrain Object Class Definitions */


/* Grass Object Class Definitions */

Grass::Grass() { }
void Grass::draw() const {
    /* todo: GRAPHICS */
}

/* End of Grass Object Class Definitions */


/* Water Object Class Definitions */

Water::Water() { }
void Water::draw() const {
    /* todo: GRAPHICS */
}

/* End of Water Object Class Definitions */
