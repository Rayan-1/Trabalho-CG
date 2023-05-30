#ifndef SCORE_H
#define SCORE_H

class Score {
public:
    Score();

    void increaseScore(int points);
    void draw();

private:
    int scoreValue;
    int positionX;
    int positionY;
    int fontSize;

    // Outras variáveis e métodos relacionados à pontuação
};

#endif
