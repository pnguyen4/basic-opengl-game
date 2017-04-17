using namespace std;

// temporary solution
struct color {
    double red;
    double blue;
    double green;
};

class MovingObject{
    protected:
        int x_coord;
        int y_coord;
        color fill;
        // color border;
        double movement_speed;
    public:
        MovingObject();
        virtual ~MovingObject();

        // pure virtual methods to be overwritten
        // movement methods might be revised to return int status codes
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void up() = 0;
        virtual void down() = 0;
        virtual double calcSpeed(double terrain_speed) const = 0;
        virtual void draw() const = 0;

        // getters return field vars. That's literally it.
        virtual int get_x_coord() const;
        virtual int get_y_coord() const;
        virtual double getMovementSpeed() const;
        virtual color getColor() const;
        /*
         * Requires: parameters to be >0 and <max-width
         * Modifies: private fields
         * Effects: limited within class
         */
        virtual void set_x_coord(int x);
        virtual void set_y_coord(int y);
        virtual void setMovementSpeed(int speed);

        virtual void setColor(double r, double b, double g);

};

class Player : public MovingObject {
    private:
        double health;
        //double attack_strength;
    public:
        Player();

        virtual void left() override;
        virtual void right() override;
        virtual void up() override;
        virtual void down() override;

        virtual void left(int step);
        virtual void right(int step);
        virtual void up(int step);
        virtual void down(int step);

        /*
         * Requires: terrain_speed > 0
         * Modifies: nothing
         * Effects: computes the net speed
         */
        virtual double calcSpeed(double terrain_speed) const override;

        // getters return field vars. That's literally it.
        virtual double getHealth() const;

        // setters
        virtual void setHealth(double hp);

        virtual void draw() const override;
};

class Enemy: public MovingObject {
    private:
        double health;
        double strength;
    public:
        Enemy();

        virtual void left() override;
        virtual void right() override;
        virtual void up() override;
        virtual void down() override;

        virtual void left(int step);
        virtual void right(int step);
        virtual void up(int step);
        virtual void down(int step);

        /*
         * Requires: terrain_speed > 0
         * Modifies: nothing
         * Effects: computes the net speed
         */
        virtual double calcSpeed(double terrain_speed) const override;

        // getters return field vars. That's literally it.
        virtual double getHealth() const;
        virtual double getStrength() const;

        // setters
        virtual void setHealth(double hp);

        double attack(Player p);
        virtual void draw() const override;
};
