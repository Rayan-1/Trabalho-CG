#include <GL/freeglut.h>
#include <GL/glut.h>
#include "player.h"
#include "enemy.h"
#include "powerUp.h"
#include "score.h"
#include "input.h"

Player player;
PowerUp powerUp(player);
Enemy enemy(player);
Score score;

void drawObjects() {
    player.draw();
    enemy.draw();
    powerUp.draw();
    score.draw();
}

void updateObjects(int windowWidth, int windowHeight) {
    player.update(windowWidth, windowHeight);
    enemy.update();
    powerUp.update();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawObjects();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            player.moveLeft();
            break;
        case 'd':
            player.moveRight();
            break;
        case 'w':
            player.moveUp();
            break;
        case 's':
            player.moveDown();
            break;
        default:
            break;
    }
}

void idle() {
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    updateObjects(windowWidth, windowHeight);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rei da Pradaria");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glClearColor(0.0, 1.0, 0.0, 1.0);

    glutMainLoop();

    return 0;
}
