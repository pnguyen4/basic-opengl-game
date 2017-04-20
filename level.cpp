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
	moving.push_back(make_unique<Enemy>);
}

Level::~Level() {

}