#include "Follower.h"
#include "SteeringBehaviors.h"


Follower::Follower(GameWorld* world,
                   Vector2D position,
                   double rotation,
                   Vector2D velocity,
                   double mass,
                   double max_force,
                   double max_speed,
                   double max_turn_rate,
                   double scale,
                   Vehicle* target,
                   Vector2D offset) :
    Vehicle(world, 
        position,
            rotation,
            velocity,
            mass,
            max_force,
            max_speed,
            max_turn_rate,
            scale) {
    Follower::Steering()->OffsetPursuitOn( target, offset );
    Follower::Steering()->SeparationOn();
    Follower::SetMaxForce( 10 );
}


Follower::~Follower() {}
