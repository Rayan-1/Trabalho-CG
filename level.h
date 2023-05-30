#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "enemy.h"
#include "powerUp.h"

class Level {
public:
    Level();

    void loadLevel(int levelNumber);
    void update();
    void draw();

private:
    int currentLevel;
    std::vector<Enemy> enemies;
    std::vector<PowerUp> powerUps;

    // Outras variáveis e métodos relacionados aos níveis
};

#endif
