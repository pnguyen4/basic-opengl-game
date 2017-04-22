//#include "graphics.hpp"
#include "level.hpp"
#include "moving_object.hpp"
#include "terrain_object.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int level_id = 1;
string file_name = "savefile.txt";

void saveLevel() {
    ofstream myfile;
    myfile.open(file_name);
    myfile << level_id;
    myfile.close();
}

int loadLevel() {
    ifstream myfile;
    myfile.open(file_name);
    int i;
    myfile >> i;
    return i;
}

int main() {

	Level map(level_id);
	Enemy enemy(1, 1, 1, 1);
	Player player(1, 1, 1);
	Grass grass(1, 1);
	Water water(1, 1);

    saveLevel();
    int test = loadLevel();
    cout << "input from text file: " << test << endl;
    cout << endl;

/*+=+=+=+= Test Code =+=+=+=*/

    cout << "***TESTING PLAYER CLASS***" << endl;

    int x = player.get_x_coord();
    int y = player.get_y_coord();
    double hp = player.getHealth();
    GameObject::color c = player.getColor();
    double s = player.getMovementSpeed();
    cout << "player xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<
        ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    player.right(); player.left(); player.up(); player.down();

    cout << "CHANGING VALUES (TESTING NORMAL #'s)" << endl;

    player.set_x_coord(10);
    player.set_y_coord(10);
    player.setMovementSpeed(20);
    player.setColor(10,10,10);
    player.setHealth(9001);
    x = player.get_x_coord();
    y = player.get_y_coord();
    hp = player.getHealth();
    c = player.getColor();
    s = player.getMovementSpeed();
    cout << "player xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<
        ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NEGATIVE #'s)" << endl;
    player.set_x_coord(-1);
    player.set_y_coord(-1);
    player.setMovementSpeed(-1);
    player.setColor(-1,-1,-1);
    player.setHealth(-1);
    x = player.get_x_coord();
    y = player.get_y_coord();
    hp = player.getHealth();
    c = player.getColor();
    s = player.getMovementSpeed();
    cout << "player xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<
        ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    ///// At this point all getters, setters, and //////
    ///// constructors should be tested for player /////

    cout << endl;
    cout << "***TESTING ENEMY CLASS***" << endl;

    x = enemy.get_x_coord();
    y = enemy.get_y_coord();
    hp = enemy.getHealth();
    c = enemy.getColor();
    s = enemy.getMovementSpeed();
    double str =  enemy.getStrength();
    cout << "enemy xcoord, ycoord, speed, health, strength, color: " << x << ", "
        <<  y <<  ", " << s << ", " << hp << ", " << str;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    enemy.right(); enemy.left(); enemy.up(); enemy.down();

    cout << "CHANGING VALUES (TESTING NORMAL #'s)" << endl;
    enemy.set_x_coord(10);
    enemy.set_y_coord(10);
    enemy.setMovementSpeed(20);
    enemy.setColor(10,10,10);
    enemy.setHealth(9001);
    enemy.setStrength(9001);
    x = enemy.get_x_coord();
    y = enemy.get_y_coord();
    hp = enemy.getHealth();
    c = enemy.getColor();
    s = enemy.getMovementSpeed();
    str = enemy.getStrength();
    cout << "enemy xcoord, ycoord, speed, health, strength, color: " << x << ", "
        <<  y <<  ", " << s << ", " << hp << ", " << str;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NEGATIVE #'s)" << endl;
    enemy.set_x_coord(-1);
    enemy.set_y_coord(-1);
    enemy.setMovementSpeed(-1);
    enemy.setColor(-1,-1,-1);
    enemy.setHealth(-1);
    enemy.setStrength(-1);
    x = enemy.get_x_coord();
    y = enemy.get_y_coord();
    hp = enemy.getHealth();
    c = enemy.getColor();
    s = enemy.getMovementSpeed();
    str = enemy.getStrength();
    cout << "enemy xcoord, ycoord, speed, health, strength, color: " << x << ", "
        <<  y <<  ", " << s << ", " << hp << ", " << str;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << endl;
    cout << "***TESTING GRASS CLASS***" << endl;

    x = grass.get_x_coord();
    y = grass.get_y_coord();
    c = grass.getColor();
    cout << "grass xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NORMAL #'s)" << endl;
    grass.set_x_coord(10);
    grass.set_y_coord(10);
    x = grass.get_x_coord();
    y = grass.get_y_coord();
    cout << "grass xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NEGATIVE #'s)" << endl;
    grass.set_x_coord(-1);
    grass.set_y_coord(-1);
    x = grass.get_x_coord();
    y = grass.get_y_coord();
    cout << "grass xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << endl;
    cout << "***TESTING WATER CLASS***" << endl;

    x = water.get_x_coord();
    y = water.get_y_coord();
    c = water.getColor();
    cout << "water xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NORMAL #'s)" << endl;
    water.set_x_coord(10);
    water.set_y_coord(10);
    x = water.get_x_coord();
    y = water.get_y_coord();
    cout << "grass xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NEGATIVE #'s)" << endl;
    water.set_x_coord(-1);
    water.set_y_coord(-1);
    x = water.get_x_coord();
    y = water.get_y_coord();
    cout << "grass xcoord, ycoord color: " << x << ", " <<  y;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    return 0;
}

/* 

main.cpp
CS120 Final Project

*/
