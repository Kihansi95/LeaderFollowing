#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <vector>
#include "SDL/SDL.h"
#include "Vehicle_keyboard.h"
#include "InputConstants.h"

class Command {
public:
    virtual ~Command() {
    }
    virtual void execute( Vehicle_keyboard *vehicle ) = 0;
    virtual InputType get_input_type() = 0;
};

class InputHandler {
private:
    // Pointers to all commands
    Command *move_up;
    Command *move_down;
    Command *move_left;
    Command *move_right;

    std::map <int, Command*> commands;

    // Gameplay context 
    std::map <int, State> state_map;
    std::map <int, Action> action_map;

    void dispatcher( std::vector<Command*> &command_queue );

    void keydown( SDL_Event &event );
    void keyup( SDL_Event &event );

    bool is_held( int key );
    bool was_pressed( int key );

public:
    InputHandler();
    ~InputHandler();
    bool input_mapping();
    bool fill( std::vector<Command*> &command_queue );
    void configure( int key, Command *command );
};

class MoveUp : public Command {
public:
    void execute( Vehicle_keyboard *vehicle ) {
        Vector2D vector( 1,0 );
        vehicle->setForce( vector );
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveLeft : public Command {
public:
    void execute( Vehicle_keyboard *vehicle ) {
        Vector2D vector( 0, -1 );
        vehicle->setForce( vector );
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveRight : public Command {
public:
    void execute( Vehicle_keyboard *vehicle ) {
        Vector2D vector( 0, 1 );
        vehicle->setForce( vector );
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveDown : public Command {
public:
    void execute( Vehicle_keyboard *vehicle ) {
        Vector2D vector( -1, 0 );
        vehicle->setForce( vector );
    }
    InputType get_input_type() {
        return STATE;
    }
};

#endif 