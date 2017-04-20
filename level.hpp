#ifndef level
#define level

#include <memory>
#include <vector>
#include "moving_object.hpp"
#include "terrain_object.hpp"
using namespace std;

class Level {
    private:
        vector<vector<unique_ptr<TerrainObject>>> map;
        vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render
		Player this_player;

    public:

		Level();
		Level(int width, int height);
		~Level();


        virtual void renderObjects();
        // virtual void playGame();
};

#endif