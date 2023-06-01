#ifndef ENEMY_H
#define ENEMY_H

#include <GL/gl.h>

class Player; // Declaração antecipada da classe Player

class Enemy {
public:
    Enemy(Player& player); // Construtor que recebe uma referência para o objeto Player

    void update();
    void draw() const;
    void checkCollision();

    float getPlayerPositionX() const;
    float getPlayerPositionY() const;
    float getPlayerWidth() const;
    float getPlayerHeight() const;

private:
    Player& player;
    float positionX;
    float positionY;
    float speed;
    float width;
    float height;

};

#endif
