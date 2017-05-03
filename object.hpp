#ifndef game_object
#define game_object
#define _USE_MATH_DEFINES 
#include <math.h>
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
