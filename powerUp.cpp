#include "powerUp.h"
#include "player.h"
#include <GL/gl.h>
#include <cmath>

PowerUp::PowerUp(const Player& player) 
    : player(player)
 {
    positionX = 100;
    positionY = 100;
    speed = 1;
    radius = 20;
    isActive = true;
    width = 0; // Inicialize a variável width conforme necessário
    height = 0; // Inicialize a variável height conforme necessário
}

void PowerUp::update() {
    // Atualiza a posição do Power-Up
    positionX += speed;
    positionY += speed;

    // Lógica de movimento ou comportamento do Power-Up
    // ...

    // Verifica colisões ou outras interações com o jogador ou obstáculos
    float playerX = player.getPositionX();
    float playerY = player.getPositionY();
    float playerWidth = player.getWidth();
    float playerHeight = player.getHeight();

    if (positionX < playerX + playerWidth &&
        positionX + width > playerX &&
        positionY < playerY + playerHeight &&
        positionY + height > playerY) {
        // Colisão com o jogador, execute a ação desejada
        // Exemplo: adicione pontos ao jogador ou ative um efeito especial
    }
}

void PowerUp::draw() const {
    if (!isActive)
        return;

    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);

    // Desenha o Power-Up como um círculo
    const int numSegments = 30;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 0.0f); // Define a cor preta para a bolinha
    glVertex2f(0.0f, 0.0f); // Posição central do círculo
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
}
