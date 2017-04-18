using namespace std;

struct color {
    double red;
    double blue;
    double green;
};

class TerrainObject {
    protected:
        int x_coord;
        int y_coord;
        double terrain_speed;
        color fill;
        // color border;
    public:
        TerrainObject();
        ~TerrainObject();

        virtual void draw() const = 0;
        virtual int get_x_coord() const;
        virtual int get_y_coord() const;
        virtual double getTerrainSpeed() const;

        virtual color getColor();

        virtual void set_x_coord(int x);
        virtual void set_y_coord(int y);
        virtual void setColor(double r, double g, double b);
};

class Grass : public TerrainObject {
    private:

    public:
        Grass();
        virtual void draw() const override;
};

class Water : public TerrainObject {
    private:

    public:
        Water();
        virtual void draw() const override;
};
