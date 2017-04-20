#include <vector>
using namespace std;

class Level {


    private:
        Vector<Vector<unique_ptr<TerrainObject>>> map;
        Vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render
		Player this_player;

    public:

		Level();
		Level(int width, int height);
		~Level();


        virtual void renderObjects();
        // virtual void playGame();
};
