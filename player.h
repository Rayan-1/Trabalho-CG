#ifndef PLAYER_H
#define PLAYER_H

#include <GL/gl.h>
#include <iostream>
#include "enemy.h"


class Player {
public:
    Player();
    void update(int windowWidth, int windowHeight);
    void draw();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool collidesWith(const Enemy& enemy) const;

    
    float getX() const { return positionX; }
    float getY() const { return positionY; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    float getPositionX() const;
    float getPositionY() const;

private:
    float positionX;
    float positionY;
    float speed;
    float width;
    float height;
};

#endif
