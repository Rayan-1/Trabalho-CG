#include <GL/glut.h>
#include <string>
#include "score.h"

Score::Score() {
    scoreValue = 0;
    positionX = 10;
    positionY = 10;
    fontSize = 20;
}

void Score::increaseScore(int points) {
    scoreValue += points;
}

void Score::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 600);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);

    glRasterPos2i(0, 0);

    std::string scoreText = "Score: " + std::to_string(scoreValue);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glPopMatrix();
}
