#ifndef terrain_object
#define terrain_object

#include "object.hpp"
using namespace std;

class TerrainObject : public GameObject {
    protected:
        int x_coord;
        int y_coord;
        double terrain_speed;
        GameObject::color fill;
        // color border;
    public:
        TerrainObject();
        ~TerrainObject();

        virtual void draw() const = 0;

	// getters return field vars
        virtual int get_x_coord() const;
        virtual int get_y_coord() const;
        virtual double getTerrainSpeed() const;
        virtual color getColor();

        /*
         * Requires: parameters to be >= 0
         * Modifies: private fields
         * Effects: limited within class
         */
        virtual void set_x_coord(int x);
        virtual void set_y_coord(int y);
        virtual void setColor(double r, double g, double b);
};

class Grass : public TerrainObject {
    private:

    public:
        Grass(int x, int y);
        virtual void draw() const override;
};

class Water : public TerrainObject {
    private:

    public:
        Water(int x, int y);
        virtual void draw() const override;
};

#endif
