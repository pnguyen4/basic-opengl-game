#include "graphics.hpp"
#include "level.hpp"
#include "moving_object.hpp"
#include "terrain_object.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int level_id = 1;
string file_name = "savefile.txt";
int width, height;
int mouse_x, mouse_y;
int wd;
Level* map;
Player* player;

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

void init() {

    /*
    saveLevel();
    int test = loadLevel();
    cout << "input from text file: " << test << endl;
    cout << endl;
    */

    map = new Level(10,20);
    player = map->getPlayer();

    width = map-> getMaxWidth() * 20;
    height = map->getMaxHeight() * 20;
    mouse_x = mouse_y = 0;
}

void initGL() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
}

void display() {
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,width,height,0.0,-1.f,1.f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    map->renderObjects();

    glFlush();
}

void kbd(unsigned char key, int x, int y) {

    glutPostRedisplay();
    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            player->down();
            break;
        case GLUT_KEY_LEFT:
            player->left();
            break;
        case GLUT_KEY_RIGHT:
            player->right();
            break;
        case GLUT_KEY_UP:
            player->up();
            break;
    }
    glutPostRedisplay();
    return;
}


void cursor(int x, int y) {
    mouse_x = x;
    mouse_y = y;

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

void timer(int extra) {
    glutTimerFunc(30, timer, 0);
    glutPostRedisplay();
}

int main(int argc, char** argv) {


    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 100);

    wd = glutCreateWindow("CS120 Game");
    glutDisplayFunc(display);
    initGL();
    glutKeyboardFunc(kbd);
    glutSpecialFunc(kbdS);
    glutPassiveMotionFunc(cursor);
    glutMouseFunc(mouse);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;

/*+=+=+=+= Test Code =+=+=+=*/

    /*
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
    */
}

/*

main.cpp
CS120 Final Project

*/
