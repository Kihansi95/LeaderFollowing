#include "InputHandler.h"

InputHandler::InputHandler() {

    // Create pointers to all commands (to apply the flyweight pattern)
    move_up = new MoveUp();
    move_down = new MoveDown();
    move_left = new MoveLeft();
    move_right = new MoveRight();

    // Player 1
    commands[SDLK_UP] = move_up;
    commands[SDLK_LEFT] = move_left;
    commands[SDLK_DOWN] = move_down;
    commands[SDLK_RIGHT] = move_right;

    // Player 2
    //commands[SDLK_w]        = move_up;
    //commands[SDLK_a]        = move_left;
    //commands[SDLK_s]        = move_down;
    //commands[SDLK_d]        = move_right;
}

void InputHandler::configure( int key, Command *command ) {
    commands[key] = command;    // key points to newly assigned command
}

bool InputHandler::fill( std::vector<Command*> &command_queue ) {
    bool exit = input_mapping();    // converts raw input datum to an action and/or state

    if ( exit ) return true;
    else {
        dispatcher( command_queue );  // fills command queue
        action_map.clear();         // clears key presses
        return false;
    }
}

bool InputHandler::input_mapping() {
    SDL_Event event;
    while ( SDL_PollEvent( &event ) )
        if ( event.type == SDL_QUIT ) return true;
        else if ( event.type == SDL_KEYDOWN ) {
            if ( event.key.keysym.sym == SDLK_ESCAPE ) return true;
            keydown( event );
        }
        else if ( event.type == SDL_KEYUP )
            keyup( event );

    return false;
}

void InputHandler::dispatcher( std::vector<Command*> &command_queue ) {
    std::map<int, Command*>::iterator iter;
    for ( iter = commands.begin(); iter != commands.end(); iter++ ) {
        if ( is_held( iter->first ) && iter->second->get_input_type() == STATE )
            command_queue.push_back( iter->second );
        else if ( was_pressed( iter->first ) && iter->second->get_input_type() == ACTION )
            command_queue.push_back( iter->second );
    }
}

void InputHandler::keydown( SDL_Event &event ) {
    if ( state_map[event.key.keysym.sym] == RELEASED )
        action_map[event.key.keysym.sym] = EXECUTE;
    state_map[event.key.keysym.sym] = PRESSED;
}

void InputHandler::keyup( SDL_Event &event ) {
    state_map[event.key.keysym.sym] = RELEASED;
}

bool InputHandler::is_held( int key ) {
    return state_map[key];
}

bool InputHandler::was_pressed( int key ) {
    return action_map[key];
}

InputHandler::~InputHandler() {
    // Delete all command pointers    
    std::map<int, Command*>::iterator iter;
    for ( iter = commands.begin(); iter != commands.end(); iter++ )
        delete iter->second;
}