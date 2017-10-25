#include "Vehicle_keyboard.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"


Vehicle_keyboard::Vehicle_keyboard (
    GameWorld* world,
    Vector2D position,
    double rotation,
    Vector2D velocity,
    double mass,
    double max_force,
    double max_speed,
    double max_turn_rate,
    double scale ) :
    Vehicle(
        world,
        position,
        rotation,
        velocity,
        mass,
        max_force,
        max_speed,
        max_turn_rate,
        scale ) {
    Vector2D ini  (0, 0);
    Vehicle_keyboard::SetScale( Vector2D( 10, 10 ) );
    Vehicle_keyboard::setForce(ini);
    Vehicle_keyboard::SetMaxSpeed( 100 );
    Vehicle_keyboard::SetMaxForce( 300 );
}

Vehicle_keyboard::~Vehicle_keyboard() {}

void Vehicle_keyboard::Update( double time_elapsed ) {
    //update the time elapsed
    m_dTimeElapsed = time_elapsed;

    //keep a record of its old position so we can update its cell later
    //in this method
    Vector2D OldPos = Pos();


    Vector2D SteeringForce;

    //calculate the combined force from each steering behavior in the 
    //vehicle's list
    SteeringForce = force_direction*MaxForce();

    //Acceleration = Force/Mass
    Vector2D acceleration = SteeringForce / m_dMass;

    //update velocity
    m_vVelocity += acceleration * time_elapsed;

    //make sure vehicle does not exceed maximum velocity
    m_vVelocity.Truncate( m_dMaxSpeed );

    //update the position
    m_vPos += m_vVelocity * time_elapsed;

    //update the heading if the vehicle has a non zero velocity
    if ( m_vVelocity.LengthSq() > 0.00000001 ) {
        m_vHeading = Vec2DNormalize( m_vVelocity );

        m_vSide = m_vHeading.Perp();
    }

    //EnforceNonPenetrationConstraint(this, World()->Agents());

    //treat the screen as a toroid
    WrapAround( m_vPos, m_pWorld->cxClient(), m_pWorld->cyClient() );

    //update the vehicle's current cell if space partitioning is turned on
    if ( Steering()->isSpacePartitioningOn() ) {
        World()->CellSpace()->UpdateEntity( this, OldPos );
    }

    if ( isSmoothingOn() ) {
        m_vSmoothedHeading = m_pHeadingSmoother->Update( Heading() );
    }
}
