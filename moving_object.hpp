#ifndef moving_object_h
#define moving_object_h

#include "object.hpp"
using namespace std;

enum direction {L, R};

class MovingObject : public GameObject {
    protected:
        int x_coord;
        int y_coord;
        color fill;
        // color border;
        double movement_speed;
	direction dir;

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

        // getters return field vars. That's literally it.
        virtual int get_x_coord() const;
        virtual int get_y_coord() const;
        virtual double getMovementSpeed() const;
        virtual color getColor() const;
        virtual double getHealth() const = 0;
        virtual double getStrength() const = 0;

        /*
         * Requires: parameters to be >0 and <max-width
         * Modifies: private fields
         * Effects: limited within class
         */
        virtual void set_x_coord(int x);
        virtual void set_y_coord(int y);
        virtual void setMovementSpeed(int speed);
        virtual void setColor(double r, double g, double b);

};

class Player : public MovingObject {
    private:
        double health;
	int state;
        //double attack_strength;
    public:
		Player();
        Player(int x, int y, double hp);

        /*
         * Requires: nothing
         * Modifies: x or y coordinate
         * Effects: moves Player one step
         */
        virtual void left() override;
        virtual void right() override;
        virtual void up() override;
        virtual void down() override;

        /*
         * Requires: nothing
         * Modifies: x or y coordinate
         * Effects: moves Player number of steps given in parameter
         */
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
        virtual double getStrength() const { return 0;}
	virtual int get_state() const;

        // setters
        virtual void setHealth(double hp);
	virtual void set_state(int s);

        virtual void draw() const override;
};

class Enemy: public MovingObject {
    private:
        double health;
        double strength;
	direction dir;
    public:
        Enemy(int x, int y, double hp, double str);

        /*
         * Requires: nothing
         * Modifies: x or y coordinate
         * Effects: moves Enemy one step
         */
        virtual void left() override;
        virtual void right() override;
        virtual void up() override;
        virtual void down() override;

        /*
         * Requires: nothing
         * Modifies: x or y coordinate
         * Effects: moves Enemy number of steps given in parameter
         */
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
        virtual double getHealth() const override;
        virtual double getStrength() const override;
	virtual direction get_direction() const;

        // setters
        virtual void setHealth(double hp);
        virtual void setStrength(double str);
	virtual void toggle_direction();

        /*
         * Requires: nothing
         * Modifies: health of player
         * Effects: reduces player health by enemy strength
         */
        double attack(Player *p);
        virtual void draw() const override;
};

#endif
