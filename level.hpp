#include <vector>
using namespace std;

class Level {


    private:
        Vector<Vector<unique_ptr<TerrainObject>>> map;
        Vector<unique_ptr<MovingObject>> moving;

        virtual void moveObjects(); //called by render

    public:

		Level();
		Level(int width, int height);
		~Level();


        virtual void renderObjects();
        // virtual void playGame();
};
