#ifndef POWERUP_H
#define POWERUP_H

#include "player.h"

class PowerUp {
public:
   PowerUp();
    PowerUp(const Player& player);

    void update();
    void draw() const;

private:
    float positionX;
    float positionY;
    float speed;
    float radius;
    bool isActive;
    Player player;
    float width; // Adicione a declaração da variável width
    float height; // Adicione a declaração da variável height
};

#endif
