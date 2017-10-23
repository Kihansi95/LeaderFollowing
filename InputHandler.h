#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <vector>
#include "SDL/SDL.h"
#include "Vehicle.h"
#include "InputConstants.h"

class Command {
public:
    virtual ~Command() {
    }
    virtual void execute( Vehicle *vehicle ) = 0;
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

    bool input_mapping();
    void dispatcher( std::vector<Command*> &command_queue );

    void keydown( SDL_Event &event );
    void keyup( SDL_Event &event );

    bool is_held( int key );
    bool was_pressed( int key );

public:
    InputHandler();
    ~InputHandler();
    bool fill( std::vector<Command*> &command_queue );
    void configure( int key, Command *command );
};

class MoveUp : public Command {
public:
    void execute( Vehicle *vehicle) {
        vehicle->force
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveLeft : public Command {
public:
    void execute( Vehicle *vehicle ) {
        //character->move_left();
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveRight : public Command {
public:
    void execute( Vehicle *vehicle ) {
        //character->move_right();
    }
    InputType get_input_type() {
        return STATE;
    }
};

class MoveDown : public Command {
public:
    void execute( Vehicle *vehicle ) {
        //character->move_down();
    }
    InputType get_input_type() {
        return STATE;
    }
};

#endif 