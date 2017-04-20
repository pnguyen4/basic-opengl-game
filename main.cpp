//#include "graphics.hpp"
//#include "level.hpp"
#include "moving_object.hpp"
#include "terrain_object.hpp"
#include <iostream>
using namespace std;

int main() {

/*+=+=+=+= Test Code =+=+=+=*/

    //Level map1();
    //MovingObject test1(); //should return compile time error
    //TerrainObject test2(); //should return compile time error
    Enemy enemy;
    Player player1;
    Player player2(1,1,1);
    Grass grass;
    Water water;

    int x = player1.get_x_coord();
    int y = player1.get_y_coord();
    double hp = player1.getHealth();
    GameObject::color c = player1.getColor();
    double s = player1.getMovementSpeed();
    cout << "player1 xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<  ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    player1.right(); player1.left(); player1.up(); player1.down();

    x = player2.get_x_coord();
    y = player2.get_y_coord();
    hp = player2.getHealth();
    c = player2.getColor();
    s = player2.getMovementSpeed();
    cout << "player2 xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<  ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    player2.right(); player2.left(); player2.up(); player2.down();

    cout << "CHANGING VALUES (TESTING NORMAL #'s)" << endl;

    player2.set_x_coord(10);
    player2.set_y_coord(10);
    player2.setMovementSpeed(20);
    player2.setColor(10,10,10);
    player2.setHealth(9001);
    x = player2.get_x_coord();
    y = player2.get_y_coord();
    hp = player2.getHealth();
    c = player2.getColor();
    s = player2.getMovementSpeed();
    cout << "player2 xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<  ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;

    cout << "CHANGING VALUES (TESTING NEGATIVE #'s)" << endl;
    player2.set_x_coord(-1);
    player2.set_y_coord(-1);
    player2.setMovementSpeed(-1);
    player2.setColor(-1,-1,-1);
    player2.setHealth(-1);
    x = player2.get_x_coord();
    y = player2.get_y_coord();
    hp = player2.getHealth();
    c = player2.getColor();
    s = player2.getMovementSpeed();
    cout << "player2 xcoord, ycoord, speed, health, color: " << x << ", "<<  y <<  ", " << s << ", " << hp;
    cout << ", {" << c.red << "," << c.green << "," << c.blue << "}" << endl;
    ///// At this point all getters, setters, and constructors should be tested for player /////

    return 0;
}
