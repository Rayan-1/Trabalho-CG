#include "input.h"

bool Input::keyStates[256] = { false };
bool Input::specialKeyStates[256] = { false };

void Input::KeyboardKeyDown(unsigned char key, int x, int y) {
    keyStates[key] = true;
}

void Input::KeyboardKeyUp(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

void Input::SpecialKeyDown(int key, int x, int y) {
    specialKeyStates[key] = true;
}

void Input::SpecialKeyUp(int key, int x, int y) {
    specialKeyStates[key] = false;
}

bool Input::KeyIsPressed(unsigned char key) {
    return keyStates[key];
}

bool Input::SpecialKeyIsPressed(int key) {
    return specialKeyStates[key];
}
