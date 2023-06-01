#ifndef INPUT_H
#define INPUT_H

class Input {
public:
    static bool KeyIsPressed(int key);
    static void KeyboardKeyDown(unsigned char key, int x, int y);
    static void KeyboardKeyUp(unsigned char key, int x, int y);
    static void SpecialKeyDown(int key, int x, int y);
    static void SpecialKeyUp(int key, int x, int y);
};

#endif
