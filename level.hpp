#ifndef level
#define level

#include <memory>
#include <vector>
#include "moving_object.hpp"
#include "terrain_object.hpp"
using namespace std;

class Level {
    private:
        int max_width;
        int max_height;
        vector<vector<unique_ptr<TerrainObject>>> map;
        vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render
		Player this_player;

    public:

		Level();
		Level(int width, int height);
        Level(int selector);

		~Level();
        int getMaxWidth() const;
        int getMaxHeight() const;

        virtual void renderObjects();
        // virtual void playGame();
        void saveLevel();
};

#endif
