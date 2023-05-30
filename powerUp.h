#ifndef POWERUP_H
#define POWERUP_H

class PowerUp {
public:
    PowerUp();

    void update();
    void draw() const;


private:
    float positionX;
    float positionY;
    float speed;
    float radius;
    bool isActive;
};

#endif
