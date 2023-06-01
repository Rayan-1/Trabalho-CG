#include "enemy.h"
#include "player.h"
#include <cstdlib>
#include <GL/glut.h>

Enemy::Enemy(Player& player) 
      : player(player)
{
    positionX = 200;
    positionY = 200;
    speed = 2;
    width = 30;
    height = 30;
}

void Enemy::update() {
    // Atualiza a posição do inimigo
    positionX += speed;
    positionY += speed;

    // Lógica de movimento ou comportamento do inimigo
    // Exemplo de movimento aleatório:
    if (rand() % 100 < 10) { // 5% de chance de mudar de direção a cada frame
        speed = -speed; // Inverte a direção do movimento
    }
    checkCollision();
   

    // ...
}

void Enemy::checkCollision() {
    float playerX = player.getPositionX();
    float playerY = player.getPositionY();
    float playerWidth = player.getWidth();
    float playerHeight = player.getHeight();

    if (positionX < playerX + playerWidth &&
        positionX + width > playerX &&
        positionY < playerY + playerHeight &&
        positionY + height > playerY) {
        // Colisão com o jogador, execute a ação desejada
        // Exemplo: diminua a vida do jogador ou destrua o inimigo
    }
}

void Enemy::draw() const {
    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Define a cor vermelha
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(width, 0.0f);
    glVertex2f(width, height);
    glVertex2f(0.0f, height);
    glEnd();
    glPopMatrix();

}

// Implementação das funções auxiliares para obter informações do jogador
float Enemy::getPlayerPositionX() const {
    return player.getX();
}

float Enemy::getPlayerPositionY() const {
    return player.getY();
}

float Enemy::getPlayerWidth() const {
    return player.getWidth();
}

float Enemy::getPlayerHeight() const {
    return player.getHeight();
}
