#include "player.h"
#include "input.h"
#include <GL/glut.h> // Inclua a biblioteca correta para usar o GLUT

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
    glColor3f(0.0f, 0.0f, 0.0f); // Define a cor preta
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
float Player::getPositionX() const {
    return positionX;
}

float Player::getPositionY() const {
    return positionY;
}

bool Input::KeyIsPressed(int key) {
    return glutGet(GLUT_KEY_UP) == key || glutGet(GLUT_KEY_DOWN) == key || glutGet(GLUT_KEY_LEFT) == key || glutGet(GLUT_KEY_RIGHT) == key;
}
