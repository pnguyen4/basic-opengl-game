#include "level.hpp"
#include "moving_object.hpp"
#include <iostream>
using namespace std;

Level::Level():Level(10,20) { }

Level::Level(int width, int height) {
    max_width = width;
    max_height = height;
    map.resize(width);

    for (int w = 0; w < width; ++w) {
        map[w].resize(height);
    }

	for (int w = 0; w < width; ++w) {
		for (int h = 0; h < height; ++h) {
			map[w][h] = make_unique<Grass>(w,h);
		}
	}

	moving.push_back(make_unique<Enemy>(1,1,2,2));
    this_player = new Player(width/2,height-1,10);
}

void Level::Init(int width, int height) {
    max_width = width;
    max_height = height;
    map.resize(width);

    for (int w = 0; w < width; ++w) {
        map[w].resize(height);
    }

	for (int w = 0; w < width; ++w) {
		for (int h = 0; h < height; ++h) {
			map[w][h] = make_unique<Grass>(w,h);
		}
	}

	moving.push_back(make_unique<Enemy>(1,1,2,2));
    this_player = new Player(width/2,height-1,10);

}

Level::Level(int selector) {
    switch(selector) {
        case 1: Init(10,20);
                break;
        case 2: Init(10,20);
                for (int w = 0; w < 10; ++w) {
                    map[w][10] = make_unique<Water>(w,10);
                }
	            moving.push_back(make_unique<Enemy>(5,5,2,2));
                break;
        default: Level();
    }
}

Level::~Level() {

}

void Level::moveObjects() {
	for (int i = 0; i < moving.size(); ++i) {
		moving[i]->left();
	}
}

void Level::renderObjects() {
	for (int i = 0; i < max_width; ++i) {
		for (int j = 0; j < max_height; ++j) {
			map[i][j]->draw();
		}
	}
	for (int k = 0; k < moving.size(); ++k) {
		moving[k]->draw();
	}
	this_player->draw();
}

int Level::getMaxWidth() const { return max_width; }
int Level::getMaxHeight() const { return max_height; }
Player* Level::getPlayer() { return this_player; }

