#include "graphics.hpp"
#include "level.hpp"
#include "moving_object.hpp"
#include "terrain_object.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum screen_state {title, menu, playgame, endgame};

screen_state screen; // for display
int level_id = 1; // loading levels
string file_name = "savefile.txt";
int width, height;
int mouse_x, mouse_y;
int wd;
int cursor_state; // used in menu hover, 0 is no highlight, 1 is top, 2 is bottom
int player_state; // main game mechanic. 0 is playing, 1 is death, 2 level complete, 3 is win
Level* map = nullptr;
Player* player = nullptr;

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

void showTitle(int state) {
	//title
	//B
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(width / 19, height / 5);
	glVertex2i(3*width/19, height/5);
	glVertex2i(3*width / 19, height/10);
	glVertex2i(width / 19, height/10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(3* width / 38, height / 10 + 3*width / 38);
	glVertex2i(5 * width / 38, height / 10 + 3*width / 38);
	glVertex2i(5 * width / 38, height / 10 + width / 38);
	glVertex2i(3 * width / 38, height / 10 + width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(3 * width / 38, height / 5 - width / 38);
	glVertex2i(5 * width / 38, height / 5 - width / 38);
	glVertex2i(5 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glVertex2i(3 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(6 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(5 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(5 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glVertex2i(6 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glEnd();
	//U
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(4*width / 19, height / 5);
	glVertex2i(6 * width / 19, height / 5);
	glVertex2i(6 * width / 19, height / 10);
	glVertex2i(4*width / 19, height / 10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(9 * width / 38, height / 5 - width/38);
	glVertex2i(11 * width / 38, height / 5 - width / 38);
	glVertex2i(11 * width / 38, height / 10);
	glVertex2i(9 * width / 38, height / 10);
	glEnd();
	//G
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(7 * width / 19, height / 5);
	glVertex2i(9 * width / 19, height / 5);
	glVertex2i(9 * width / 19, height / 10);
	glVertex2i(7 * width / 19, height / 10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(15 * width / 38, height / 5 - width / 38);
	glVertex2i(17 * width / 38, height / 5 - width / 38);
	glVertex2i(17 * width / 38, height / 10 + width / 38);
	glVertex2i(15 * width / 38, height / 10 + width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(18 * width / 38, height / 5 - 4 * width / 38);
	glVertex2i(17 * width / 38, height / 5 - 4 * width / 38);
	glVertex2i(17 * width / 38, height / 10 + width / 38);
	glVertex2i(18 * width / 38, height / 10 + width / 38);
	glEnd();
	//G
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(10 * width / 19, height / 5);
	glVertex2i(12 * width / 19, height / 5);
	glVertex2i(12 * width / 19, height / 10);
	glVertex2i(10 * width / 19, height / 10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(21 * width / 38, height / 5 - width / 38);
	glVertex2i(23 * width / 38, height / 5 - width / 38);
	glVertex2i(23 * width / 38, height / 10 + width / 38);
	glVertex2i(21 * width / 38, height / 10 + width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(24 * width / 38, height / 5 - 4 * width / 38);
	glVertex2i(23 * width / 38, height / 5 - 4 * width / 38);
	glVertex2i(23 * width / 38, height / 10 + width / 38);
	glVertex2i(24 * width / 38, height / 10 + width / 38);
	glEnd();
	//E
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(13 * width / 19, height / 5);
	glVertex2i(15 * width / 19, height / 5);
	glVertex2i(15 * width / 19, height / 10);
	glVertex2i(13 * width / 19, height / 10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(27 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(30 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(30 * width / 38, height / 10 + width / 38);
	glVertex2i(27 * width / 38, height / 10 + width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(27 * width / 38, height / 5 - width / 38);
	glVertex2i(30 * width / 38, height / 5 - width / 38);
	glVertex2i(30 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glVertex2i(27 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glEnd();
	//R
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(16 * width / 19, height / 5);
	glVertex2i(18 * width / 19, height / 5);
	glVertex2i(18 * width / 19, height / 10);
	glVertex2i(16 * width / 19, height / 10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(33 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(35 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(35 * width / 38, height / 10 + width / 38);
	glVertex2i(33 * width / 38, height / 10 + width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(33 * width / 38, height / 5);
	glVertex2i(35 * width / 38, height / 5);
	glVertex2i(35 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glVertex2i(33 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(36 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(35 * width / 38, height / 10 + 3 * width / 38);
	glVertex2i(35 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glVertex2i(36 * width / 38, height / 5 - width / 38 - 3 * width / 38);
	glEnd();

	//options
    glBegin(GL_QUADS);
    glColor3f(.5,0,.5);
    glVertex2i(width/4,height/4);
    glVertex2i(width-(width/4),height/4);
    glVertex2i(width-(width/4),height-(height/4));
    glVertex2i(width/4,height-(height/4));
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2i(width/4,height/2);
    glVertex2i(width-(width/4),height/2);
    glVertex2i(width-(width/4),(height/2)+2);
    glVertex2i(width/4,(height/2)+2);
    glEnd();
    if(state == 1) {
        glBegin(GL_QUADS);
        glColor3f(1,0,1);
        glVertex2i(width/4,height/4);
        glVertex2i(width-(width/4),height/4);
        glVertex2i(width-(width/4),height/2);
        glVertex2i(width/4,height/2);
        glEnd();
    }
    if(state == 2) {
        glBegin(GL_QUADS);
        glColor3f(1,0,1);
        glVertex2i(width/4,height/2);
        glVertex2i(width-(width/4),height/2);
        glVertex2i(width-(width/4),height-(height/4));
        glVertex2i(width/4,height-(height/4));
        glEnd();
    }
    string m1 = "CLICK TO LOAD";
    glColor3f(1,1,1);
    glRasterPos2i(1.25*width/4,1.5*height/4);
    for (int i = 0; i < m1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, m1[i]);
    }
    string m2 = "CLICK TO START";
    glColor3f(1,1,1);
    glRasterPos2i(1.25*width/4,1.25*height/2);
    for (int i = 0; i < m2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, m2[i]);
    }
    string lvl = "LEVEL LOADED: " + to_string(level_id);
    glColor3f(1,1,1);
    glRasterPos2i(5,10);
    for (int i = 0; i < lvl.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, lvl[i]);
    }

}

void playGame() {
    map->renderObjects();
}

void showMenu(int state) {
    map->renderObjects();
    // state == 0 should be default, not a special case
    glBegin(GL_QUADS);
    glColor3f(.5,0,.5);
    glVertex2i(width/4,height/4);
    glVertex2i(width-(width/4),height/4);
    glVertex2i(width-(width/4),height-(height/4));
    glVertex2i(width/4,height-(height/4));
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2i(width/4,height/2);
    glVertex2i(width-(width/4),height/2);
    glVertex2i(width-(width/4),(height/2)+2);
    glVertex2i(width/4,(height/2)+2);
    glEnd();
    if(state == 1) {
        glBegin(GL_QUADS);
        glColor3f(1,0,1);
        glVertex2i(width/4,height/4);
        glVertex2i(width-(width/4),height/4);
        glVertex2i(width-(width/4),height/2);
        glVertex2i(width/4,height/2);
        glEnd();
    }
    if(state == 2) {
        glBegin(GL_QUADS);
        glColor3f(1,0,1);
        glVertex2i(width/4,height/2);
        glVertex2i(width-(width/4),height/2);
        glVertex2i(width-(width/4),height-(height/4));
        glVertex2i(width/4,height-(height/4));
        glEnd();
    }
    string m1 = "CLICK TO SAVE";
    glColor3f(1,1,1);
    glRasterPos2i(1.25*width/4,1.5*height/4);
    for (int i = 0; i < m1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, m1[i]);
    }
    string m2 = "CLICK TO QUIT";
    glColor3f(1,1,1);
    glRasterPos2i(1.25*width/4,1.25*height/2);
    for (int i = 0; i < m2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, m2[i]);
    }
}

void endGame(int pstate) {
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(0,0);
    glVertex2i(width,0);
    glVertex2i(width,height);
    glVertex2i(0,height);
    glEnd();

    string end;
    if(pstate == 1) {
        end = "DEAD. RESTART(Y/N)?";
		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(width / 4, 3*height/4);
		glVertex2i(3 * width / 4, 3 * height / 4);
		glVertex2i(3 * width / 4, height);
		glVertex2i(width / 4, height);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(width/2, 3 * height / 4);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2) + (width/4) * cos(i * M_PI / 180.0),
				(3 * height / 4) + (width/4) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex2i(width/2 - 1, 5 * height / 6);
		glVertex2i(width/2 + 1, 5 * height / 6);
		glVertex2i(width/2 +1, height);
		glVertex2i(width/2 -1, height);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2i(width / 2, 5 * height / 6);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2) + (width / 10) * cos(i * M_PI / 180.0),
				(5 * height / 6) + (width / 10) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 0);
		glVertex2i(width / 2, 5 * height / 6);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2) + (width / 20) * cos(i * M_PI / 180.0),
				(5 * height / 6) + (width / 20) * sin(i * M_PI / 180.0));
		}
		glEnd();
    }
    else if(pstate == 2) {
        end = "CLICK FOR NEXT LEVEL";
    }
    else if(pstate == 3) {
        end = "WIN! RESTART(Y/N)?";
		//draw head
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2, 3*height/4);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i(width / 2 + (width/6) * cos(i * M_PI / 180.0),
				(3 * height / 4) + (width/6) * sin(i * M_PI / 180.0));
		}
		glEnd();

		//draw body
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		glVertex2i(width / 2, 8 * height / 10);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i(width / 2 + (width / 5) * cos(i * M_PI / 180.0),
				(8 * height / 10) + (width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();

		//draw crown
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2i(width / 3, 5.75 * height / 10);
		glVertex2i(2*width / 3, 5.75 * height / 10);
		glVertex2i(2*width / 3, 6.25*height/10);
		glVertex2i(width / 3, 6.25*height/10);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 0);
		glVertex2i(width / 2, 5.4 * height / 10);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i(width / 2 + (width / 9) * cos(i * M_PI / 180.0),
				(5.4 * height / 10) + (width / 9) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 0);
		glVertex2i(width / 2 + (width / 9), 5.4 * height / 10);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 + (width / 9)) + (width / 9) * cos(i * M_PI / 180.0),
				(5.4 * height / 10) + (width / 9) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 0);
		glVertex2i(width / 2 - (width / 9), 5.4 * height / 10);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 - (width / 9)) + (width / 9) * cos(i * M_PI / 180.0),
				(5.4 * height / 10) + (width / 9) * sin(i * M_PI / 180.0));
		}
		glEnd();

		//draw spots
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 - width / 10, 3*height / 4);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 - width / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(3*height / 4) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 + width / 10, 3 * height / 4);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 + width / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(3 * height / 4) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();
		//
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 - (2 * width / 4) / 10, 4 * height / 5);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 - (2 * width / 4) / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(4 * height / 5) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 + (2 * width / 4) / 10, 4 * height / 5);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 + (2 * width / 4) / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(4 * height / 5) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();
		//
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 - width / 10, 6 * height / 7);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 - width / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(6 * height / 7) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2i(width / 2 + width / 10, 6 * height / 7);
		for (int i = 0; i <= 360; ++i) {
			glVertex2i((width / 2 + width / 10) + .08*(2 * width / 5) * cos(i * M_PI / 180.0),
				(6 * height / 7) + .08*(2 * width / 5) * sin(i * M_PI / 180.0));
		}
		glEnd();

    }
    glColor3f(1,1,1);
    glRasterPos2i(width/4,height/2);
    for (int i = 0; i < end.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, end[i]);
    }

}

void init() {

    screen = title;
    map = new Level(level_id);
    player = map->getPlayer();
    player_state = 0;

    width = map->getMaxWidth() * player->side_length;
    height = map->getMaxHeight() * player->side_length;
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

    switch(screen) {
        case playgame:
            playGame();
            break;
        case menu:
            showMenu(cursor_state);
            break;
        case title:
            showTitle(cursor_state);
            break;
        case endgame:
            endGame(player->get_state());
    }

    glFlush();
}

void kbd(unsigned char key, int x, int y) {
    // pressed escape
    if (key == 27) {
        if (screen == playgame) {
            screen = menu;
        }
        else if (screen == menu) {
            screen = playgame;
        }
    }
    if (screen == endgame && (player->get_state() == 3 || player->get_state() == 1)) {
        // pressed y
        if (key == 89 || key == 121) {
            level_id = 1;
            init();
            screen = playgame;
        // pressed n
        } else if (key == 78 || key == 110) {
            glutDestroyWindow(wd);
            exit(0);
        }
    }

    glutPostRedisplay();
    return;
}

void kbdS(int key, int x, int y) {
    if (screen == playgame) {
        switch(key) {
            case GLUT_KEY_DOWN:
                if (player->get_y_coord() < (map->getMaxHeight() -1)) {
                    player->down();
                }
                break;

            case GLUT_KEY_LEFT:
                if (player->get_x_coord() > 0) {
                    player->left();
                }
                break;

            case GLUT_KEY_RIGHT:
                if (player->get_x_coord() < (map->getMaxWidth() -1)) {
                    player->right();
                }
                break;

            case GLUT_KEY_UP:
                if (player->get_y_coord() > 0) {
                    player->up();
                }
                break;
        }

        if(player->get_y_coord() == 0) {
            screen = endgame;
            if(level_id < 3) {
                player->set_state(2); // you beat the level
            } else { player->set_state(3); } // you win the game
        }
    }
    return;
}


void cursor(int x, int y) {
    mouse_x = x;
    mouse_y = y;

    if(x >= width/4 && x <= width-(width/4) && y >= height/4 && y <= height/2) {
        cursor_state = 1;
    }
    else if(x >= width/4 && x <= width-(width/4) && y <= height-(height/4) && y >= height/2) {
        cursor_state = 2;
    }
    else { cursor_state = 0; }
}

void mouse(int button, int state, int x, int y) {
    if(x >= width/4 && x <= width-(width/4) && y >= height/4
        && y <= height/2 && screen == title) {
        level_id = loadLevel();
        if(level_id > 3) {
            cout << "error, no such level exists" << endl;
            level_id = 1;
        }
        init();
    }
    else if(x >= width/4 && x <= width-(width/4) && y <= height-(height/4)
            && y >= height/2 && screen == title) {
        screen = playgame;
    }
    if(x >= width/4 && x <= width-(width/4) && y >= height/4
        && y <= height/2 && screen == menu) {
        saveLevel();
    }
    else if(x >= width/4 && x <= width-(width/4) && y <= height-(height/4)
            && y >= height/2 && screen == menu) {
        glutDestroyWindow(wd);
        exit(0);
    }
    if(screen == endgame && player->get_state() == 2) {
        level_id++;
        init();
        screen = playgame;
    }

    glutPostRedisplay();
}

void timer(int extra) {
    if (screen == playgame) {
    	if(map->checkOverlap() || ( (map->getCurrentTerrain() == water) && (player->get_x_coord() < 1) )) {
			player->set_state(1); // you died
			screen = endgame;
		}
    }
    glutTimerFunc(120, timer, 0);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 100);

    wd = glutCreateWindow("Bugger");
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
