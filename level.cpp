#include "level.h"
#include <GL/gl.h>

Level::Level() {
    currentLevel = 0;
}

void Level::loadLevel(int levelNumber) {
    // Lógica para carregar o nível específico, como configurar inimigos, power-ups, etc.
    // Pode usar o parâmetro levelNumber para determinar o nível a ser carregado
    // e preencher o vetor de inimigos (enemies) e power-ups (powerUps) conforme necessário.
    // Exemplo:
    if (levelNumber == 1) {
        enemies.push_back(Enemy(/* parâmetros do inimigo */));
        enemies.push_back(Enemy(/* parâmetros do inimigo */));
        powerUps.push_back(PowerUp(/* parâmetros do power-up */));
    }
    // ...
}

void Level::update() {
    // Lógica para atualizar o estado dos inimigos, power-ups e outros elementos do nível
    for (auto& enemy : enemies) {
        enemy.update();
    }

    for (auto& powerUp : powerUps) {
        powerUp.update();
    }

    // Lógica para verificar colisões, pontuação, etc.
}

void Level::draw() {
    // Lógica para desenhar os elementos do nível na tela
    for (const auto& enemy : enemies) {
        enemy.draw();
    }

    for (const auto& powerUp : powerUps) {
        powerUp.draw();
    }
}
