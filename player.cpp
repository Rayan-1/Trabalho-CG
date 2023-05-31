#include "player.h"
#include "input.h"
#include <GLFW/glfw3.h>

Player::Player() {
    positionX = 0;
    positionY = 0;
    speed = 100;
    width = 50;
    height = 50;
}

void Player::update(int windowWidth, int windowHeight) {
    if (Input::KeyIsPressed('a'))
        positionX -= speed;
    if (Input::KeyIsPressed('d'))
        positionX += speed;
    if (Input::KeyIsPressed('w'))
        positionY -= speed;
    if (Input::KeyIsPressed('s'))
        positionY += speed;

    // Limit player movement within window bounds
    if (positionX < 0)
        positionX = 0;
    if (positionX > windowWidth - width)
        positionX = windowWidth - width;
    if (positionY < 0)
        positionY = 0;
    if (positionY > windowHeight - height)
        positionY = windowHeight - height;
}

void Player::draw() {
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
void Player::moveLeft() {
    positionX -= speed;
}

void Player::moveRight() {
    positionX += speed;
}

void Player::moveUp() {
    positionY -= speed;
}

void Player::moveDown() {
    positionY += speed;
}


bool Input::KeyIsPressed(int key) {
    // Implementação da função

    // Adicione seu código aqui

    // Retorne um valor (verdadeiro ou falso) com base na entrada da tecla
    return true; // Substitua pela sua implementação
}

