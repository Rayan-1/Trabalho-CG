#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy();

    void draw() const;
    void update();

private:
    float positionX;
    float positionY;
    float speed;
    float width;
    float height;
};

#endif
