#pragma once 
#include "Vehicle.h"


class GameWorld;
class SteeringBehavior;

class Vehicle_keyboard : public Vehicle{
public:

    Vehicle_keyboard( GameWorld* world,
        Vector2D position,
        double rotation,
        Vector2D velocity,
        double mass,
        double max_force,
        double max_speed,
        double max_turn_rate,
        double scale );

    void Update( double time_elapsed );

    void setForce( Vector2D force ) {
        force_direction = force;
    }
    ~Vehicle_keyboard();

private:
    Vector2D force_direction;

};
