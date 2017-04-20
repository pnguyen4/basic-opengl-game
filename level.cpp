#include "level.hpp"

Level::Level() {
    for (int j = 0; j < 20; ++j) {
        for (int k = 0; k < 20; ++k) {
            map[j][k] = make_unique<Grass>(j,k);
        }
    }

    moving[0] = make_unique<Enemy>(5,5,10,1);
    moving[2] = make_unique<Enemy>(15,15,10,1);
}

void Level::renderObjects() {
    for (int j = 0; j < 20; ++j) {
        for (int k = 0; k < 20; ++k) {
            map[j][k]->draw();
        }
    }
}

void Level::moveObjects() {
    for (int i = 0; i < moving.size(); ++i) {
        moving[i]->left(); //every call of this function makes the enemies walk left
    }
}
