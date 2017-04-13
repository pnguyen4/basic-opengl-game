#include "moving_object.hpp"
using namespace std;


/* Moving Object Class Definitions */

MovingObject::MovingObject() { }
MovingObject::~MovingObject() { }
int MovingObject::get_x_coord() const { return x_coord; }
int MovingObject::get_y_coord() const { return y_coord; }
double MovingObject::getMovementSpeed() const { return movement_speed; }

void MovingObject::set_x_coord(int x) {
    x_coord = x;
    /* todo: check for valid input */
}

void MovingObject::set_y_coord(int y) {
    y_coord = y;
    /* todo: check for valid input */
}

void MovingObject::setMovementSpeed(int speed) {
    movement_speed = speed;
    /* todo: check for valid input */
}

/* End of MovingObject Class Definitions */



/* Player Object Class Definitions */

Player::Player() { }
double Player::getHealth() const { return health; }

// i'll think of something for these
void Player::left() { }
void Player::right() { }
void Player::up() { }
void Player::down() { }

double Player::calcSpeed(double terrain_speed) const {
    if (terrain_speed > 0) {
        return movement_speed - terrain_speed; // compute the delta
    }
}

void Player::draw() const {
    /* todo: GRAPHICS */
}

/* End of Player Class Definitions */
