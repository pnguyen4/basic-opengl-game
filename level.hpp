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
		Player* this_player;

    public:

		Level();
		Level(int width, int height);
        Level(int selector);

		~Level();
        int getMaxWidth() const;
        int getMaxHeight() const;
        Player* getPlayer();

        /*
         * Requires: map and moving vectors must have dimensions >0
         * Modifies: nothing
         * Effects: renders player and moving objects on terrain map
         */
        virtual void renderObjects();

        // virtual void playGame();
};

#endif
