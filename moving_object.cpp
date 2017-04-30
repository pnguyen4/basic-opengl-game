#include "moving_object.hpp"
#include "level.hpp"
#include "graphics.hpp"
#include <iostream>

#define _USE_MATH_DEFINES 
#include <math.h>

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
        x_coord = 0;
    }
}

void MovingObject::set_y_coord(int y) {
    if (y >= 0) {
        y_coord = y;
    } else {
        cout << "error: negative value for y" << endl;
        y_coord = 0;
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
    setMovementSpeed(1);
    set_y_coord(y);
    set_x_coord(x);
    setHealth(hp);
    setColor(1,0,0);
}

double Player::getHealth() const { return health; }
void Player::setHealth(double hp) {
    if (hp > 0) {
        health = hp;
    } else {
        cout << "error: negative value for health value" << endl;
        health = 1;
    }
}

// let the draw function handle when bounds are hit,
// in that case use set_x_coord and set_y_coord to go to other side of screen
void Player::left() {
    set_x_coord(get_x_coord() - 1);
}
void Player::right() {
    set_x_coord(get_x_coord() + 1);
}
void Player::up() {
    set_y_coord(get_y_coord() - 1);
}
void Player::down() {
    set_y_coord(get_y_coord() + 1);
}

void Player::left(int step) {
    set_x_coord(get_x_coord() - step);
}
void Player::right(int step) {
    set_x_coord(get_x_coord() + step);
}
void Player::up(int step) {
    set_y_coord(get_y_coord() - step);
}
void Player::down(int step) {
    set_y_coord(get_y_coord() + step);
}

double Player::calcSpeed(double terrain_speed) const {
    if (terrain_speed > 0) {
        return movement_speed - terrain_speed; // compute the delta
    }
}

void Player::draw() const {
	
	//draw head
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2, get_y_coord()*side_length + side_length / 3);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2) + .3*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 3) + .3*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	//draw body
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(255, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2, get_y_coord()*side_length + side_length / 1.7);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2) + .4*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7) + .4*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	//draw spots
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 - side_length / 10, get_y_coord()*side_length + side_length / 1.7);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 - side_length / 10) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 + side_length / 10, get_y_coord()*side_length + side_length / 1.7);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 + side_length / 10) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 - side_length / 5, get_y_coord()*side_length + side_length / 1.7 - side_length / 5);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 - side_length / 5) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7 - side_length / 5) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 + side_length / 5, get_y_coord()*side_length + side_length / 1.7 - side_length / 5);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 + side_length / 5) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7 - side_length / 5) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 - side_length / 5, get_y_coord()*side_length + side_length / 1.7 + side_length / 5);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 - side_length / 5) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7 + side_length / 5) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2i(get_x_coord()*side_length + side_length / 2 + side_length / 5, get_y_coord()*side_length + side_length / 1.7 + side_length / 5);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i((get_x_coord()*side_length + side_length / 2 + side_length / 5) + .08*side_length * cos(i * M_PI / 180.0),
			(get_y_coord()*side_length + side_length / 1.7 + side_length / 5) + .08*side_length * sin(i * M_PI / 180.0));
	}
	glEnd();

}

/* End of Player Class Definitions */


/* Enemy Object Class Definitions */

Enemy::Enemy(int x, int y, double hp, double str) {
    setHealth(hp);
    set_x_coord(x);
    set_y_coord(y);
    setStrength(str);
    setMovementSpeed(1);
    setColor(0,0.5,0.8);
	dir = R;
}

double Enemy::getHealth() const { return health; }
double Enemy::getStrength() const { return strength; }
direction Enemy::get_direction() const { return dir; }

void Enemy::setHealth(double hp) {
    if (hp > 0) {
        health = hp;
    } else {
        cout << "error: negative value for health value" << endl;
        health = 1;
    }
}
void Enemy::setStrength(double str) {
    if (str > 0) {
        strength = str;
    } else {
        cout << "error: negative value for strength value" << endl;
        strength = 1;
    }
}

void Enemy::toggle_direction() {
	if (dir == L) {
		dir = R;
	} else {
		dir = L;
	}
}

void Enemy::left() {
    set_x_coord(get_x_coord() - 1);
}
void Enemy::right() {
    set_x_coord(get_x_coord() + 1);
}
void Enemy::up() {
    set_y_coord(get_y_coord() - 1);
}
void Enemy::down() {
    set_y_coord(get_y_coord() + 1);
}

void Enemy::left(int step) {
    set_x_coord(get_x_coord() - step);
}
void Enemy::right(int step) {
    set_x_coord(get_x_coord() + step);
}
void Enemy::up(int step) {
    set_y_coord(get_y_coord() - step);
}
void Enemy::down(int step) {
    set_y_coord(get_y_coord() + step);
}

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
    glBegin(GL_QUADS);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(x_coord*20, y_coord*20);
    glVertex2i((x_coord*20)+20, y_coord*20);
    glVertex2i((x_coord*20)+20, (y_coord*20)+20);
    glVertex2i(x_coord*20, (y_coord*20)+20);
    glEnd();
}

/* End of Player Class Definitions */
