#include "level.hpp"

Level::Level() {
	Level(10, 20);
}

Level::Level(int width, int height) {
	for (int w = 0; w < width; ++w) {
		for (int h = 0; h < height; ++h) {
			map[w][h] = make_unique<Grass>(w,h);
		}
	}
	moving.push_back(make_unique<Enemy>(1,1,2,2));
}

Level::~Level() {

}

void Level::moveObjects() {
	for (int i = 0; i < moving.size(); ++i) {
		moving[i]->left();
	}
}

void Level::renderObjects() {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			map[i][j]->draw();
		}
	}
	for (int k = 0; k < moving.size(); ++k) {
		moving[k]->draw();
	}
	this_player.draw();
}