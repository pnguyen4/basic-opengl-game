using namespace std;

struct color {
    double red;
    double blue;
    double green;
}

class MovingObject{
    private:
        int x_coord;
        int y_coord
        double movementSpeed;
        color fill;
        // color border;
    public:
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void up() = 0;
        virtual void down() = 0;

        virtual double calcSpeed() const = 0;
        virtual int get_x_coord() const;
        virtual int get_y_coord() const;
        virtual double getMovementSpeed() const;

        virtual void set_x_coord();
        virtual void set_y_coord();
        virtual void setMovementSpeed();

        virtual void draw() const = 0;
};

class Player : public MovingObject {
    private:
        double health;
    public:
        virtual void draw() override;
        virtual void left() override;
        virtual void right() override;
        virtual void up() override;
        virtual void down() override;

        virtual void calcSpeed override;
        virtual void getHealth();
}
