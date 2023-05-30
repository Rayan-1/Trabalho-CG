#include "enemy.h"
#include <GL/gl.h>

Enemy::Enemy() {
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
    // ...

    // Verifica colisões ou outras interações com o jogador ou obstáculos
    // ...
}

void Enemy::draw() const {
    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(width, 0.0f);
    glVertex2f(width, height);
    glVertex2f(0.0f, height);
    glEnd();
    glPopMatrix();
}
