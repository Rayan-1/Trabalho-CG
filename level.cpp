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

        // Verificar colisão entre jogador e inimigo
        if (checkCollision(player, enemy)) {
            // Lógica para tratar a colisão
            player.handleCollision();
    }

    for (auto& powerUp : powerUps) {
        powerUp.update();
    }

    // Lógica para verificar colisões, pontuação, etc.
    if (checkCollision(player, powerUp)) {
            // Lógica para tratar a colisão
            player.handlePowerUpCollision(powerUp);
            // Remover o power-up do vetor de power-ups, se necessário
            // powerUps.erase(std::remove(powerUps.begin(), powerUps.end(), powerUp), powerUps.end());
        }
}

bool Level::checkCollision(const Player& player, const GameObject& object) {
    // Lógica para verificar se ocorreu uma colisão entre o jogador e o objeto
    // Retorne true se houver colisão e false caso contrário

    // Exemplo simples: verificando se os retângulos de colisão se sobrepõem
    float playerLeft = player.getX();
    float playerRight = player.getX() + player.getWidth();
    float playerTop = player.getY();
    float playerBottom = player.getY() + player.getHeight();

    float objectLeft = object.getX();
    float objectRight = object.getX() + object.getWidth();
    float objectTop = object.getY();
    float objectBottom = object.getY() + object.getHeight();

    if (playerRight >= objectLeft && playerLeft <= objectRight && playerBottom >= objectTop && playerTop <= objectBottom) {
        return true;
    }

    return false;
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
