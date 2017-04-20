#ifndef level_
#define level_

#include <vector>
#include <memory>
#include "terrain_object.hpp"
#include "moving_object.hpp"
using namespace std;

/*================================================/
 *      ***    THIS NEEDS SOME WORK    ***     /
 *===============================================*/


class Level {
    private:
        vector<vector<unique_ptr<TerrainObject>>> map;
        vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render

    public:
        Level();
        //Level (int select); //idea: levels 0-9 pregenerated
        virtual void renderObjects();
        // virtual void playGame();
};

#endif
