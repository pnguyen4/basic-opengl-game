#include <vector>
using namespace std;

/*================================================/
 *      ***    THIS NEEDS LOTS OF WORK    ***     /
 *===============================================*/


class Level {
    private:
        Vector<Vector<unique_ptr<TerrainObject>> map;
        Vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render

    public:
        virtual void renderObjects();
        // virtual void playGame();
};
