#include "moving_object.hpp"
#include "level.hpp"
#include <iostream>
using namespace std;
/* Moving Object Class Definitions */

MovingObject::MovingObject() { }
MovingObject::~MovingObject() { }

int MovingObject::get_x_coord() const { return x_coord; }
int MovingObject::get_y_coord() const { return y_coord; }
double MovingObject::getMovementSpeed() const { return movement_speed; }
GameObject::color MovingObject::getColor() const { return fill; }

void MovingObject::set_x_coord(int x) {
    if (x >= 0) {
        x_coord = x;
    } else {
        cout << "error: negative value for x" << endl;
        x_coord = 1;
    }
}

void MovingObject::set_y_coord(int y) {
    if (y >= 0) {
        y_coord = y;
    } else {
        cout << "error: negative value for y" << endl;
        y_coord = 1;
    }
}

void MovingObject::setMovementSpeed(int speed) {
    if (speed >= 0) {
        movement_speed = speed;
    } else {
        cout << "error: negative value for movement_speed" << endl;
        movement_speed = 1;
    }
}

void MovingObject::setColor(double r, double g, double b) {
    if (r >=0 && g >=0 && b >= 0) {
        fill = {r,g,b};
    } else {
        cout << "error: negative value for a color value" << endl;
        fill = {0,0,0};
    }
}

/* End of MovingObject Class Definitions */


/* Player Object Class Definitions */

Player::Player() {
	Player(3, 3, 10);
}

Player::Player(int x, int y, double hp) {
    setColor(0,0,0);
    setMovementSpeed(1);
    set_y_coord(y);
    set_x_coord(x);
    setHealth(hp);
}

double Player::getHealth() const { return health; }
void Player::setHealth(double hp) { health = hp; }

// let the draw function handle when bounds are hit,
// in that case use set_x_coord and set_y_coord to go to other side of screen
void Player::left() { x_coord - 1; }
void Player::right() { x_coord + 1; }
void Player::up() { y_coord - 1; }
void Player::down() { y_coord + 1; }

void Player::left(int step) { x_coord - step; }
void Player::right(int step) { x_coord + step; }
void Player::up(int step) { y_coord - step; }
void Player::down(int step) {y_coord + step; }

double Player::calcSpeed(double terrain_speed) const {
    if (terrain_speed > 0) {
        return movement_speed - terrain_speed; // compute the delta
    }
}

void Player::draw() const {
    /* todo: GRAPHICS */
}

/* End of Player Class Definitions */


/* Enemy Object Class Definitions */

Enemy::Enemy(int x, int y, double hp, double str) {
    setHealth(hp);
    set_x_coord(x);
    set_y_coord(y);
    setStrength(str);
    setMovementSpeed(1);
    setColor(0,0,0);
}

double Enemy::getHealth() const { return health; }
double Enemy::getStrength() const { return strength; }
void Enemy::setHealth(double hp) {
    if (health > 0) {
        health = hp;
    } else {
        cout << "error: negative value for health value" << endl;
        health = 1;
    }
}
void Enemy::setStrength(double str) {
    if (strength > 0) {
        strength = str;
    } else {
        cout << "error: negative value for strength value" << endl;
        strength = 1;
    }
}

void Enemy::left() { x_coord - 1; }
void Enemy::right() { x_coord + 1; }
void Enemy::up() { y_coord - 1; }
void Enemy::down() { y_coord + 1; }

void Enemy::left(int step) { x_coord - step; }
void Enemy::right(int step) { x_coord + step; }
void Enemy::up(int step) { y_coord - step; }
void Enemy::down(int step) {y_coord + step; }

double Enemy::calcSpeed(double terrain_speed) const {
    if (terrain_speed > 0) {
        return movement_speed - terrain_speed; // compute the delta
    }
}

double Enemy::attack(Player *p) {
    p->setHealth(p->getHealth() - strength);
    return strength;
}

void Enemy::draw() const {
    /* todo: GRAPHICS */
}

/* End of Player Class Definitions */
