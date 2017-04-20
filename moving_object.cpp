#include "moving_object.hpp"
using namespace std;
/* Moving Object Class Definitions */

MovingObject::MovingObject() { }
MovingObject::~MovingObject() { }

int MovingObject::get_x_coord() const { return x_coord; }
int MovingObject::get_y_coord() const { return y_coord; }
double MovingObject::getMovementSpeed() const { return movement_speed; }
GameObject::color MovingObject::getColor() const { return fill; }

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

void MovingObject::setColor(double r, double g, double b) {
    fill = {r,g,b};
    /* todo: check for valid input */
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
void Enemy::setHealth(double hp) { health = hp; }
void Enemy::setStrength(double str) { strength = str; }

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
