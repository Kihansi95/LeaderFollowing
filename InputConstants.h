#ifndef INPUT_CONSTANTS_HPP
#define INPUT_CONSTANTS_HPP

enum InputType {
    ACTION,
    STATE,
    RANGE
};

enum Action {
    EXECUTE = true,
    STOP = false
};

enum State {
    PRESSED = true,
    RELEASED = false
};

#endif // INPUT_CONSTANTS_HPP