#ifndef PLAYER_H
#define PLAYER_H

#include <GL/gl.h>

class Player {
public:
    Player();
    void update(int windowWidth, int windowHeight);
    void draw();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

private:
    float positionX;
    float positionY;
    float speed;
    float width;
    float height;
};

#endif
