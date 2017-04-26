#ifndef game_object
#define game_object
using namespace std;

class GameObject {
    public:
        struct color {
            double red;
            double green;
            double blue;
        };
        virtual void draw() const = 0;

		int side_length = 20;
};

#endif
