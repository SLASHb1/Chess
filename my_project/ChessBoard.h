#pragma once
#include "utilityBox.h"
#include <SFML/Graphics.hpp>

class ChessBoard {
private:
    sf::RectangleShape rectangle[64];
    sf::Texture texture[64];
    sf::Sprite sprite[64];
    Identity box;
    bool isMove;
    float dx = 0, dy = 0;
    sf::Vector2f oldPos, newPos;
    int n;
    int cc, turn = 1;
    int alliance, position;
    sf::Vector2f firstPos, secondPos;
    int cap = 0;

    void loadTextures();

    void loadBoard();

    void drawBoard(sf::RenderWindow& window);

    void endGame(sf::RenderWindow& window);

    void clearBoard();

    void gripFigure(int j, sf::Vector2i pos);

    void makeMove(int j, int spritePos, sf::RenderWindow& window);

public:

    int spritePositions[64] = {
        0, 1, 2, 3, 4, 5, 6, 7,
        8, 9, 10, 11, 12, 13, 14, 15,
        64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64,
        48, 49, 50, 51, 52, 53, 54, 55,
        56, 57, 58, 59, 60, 61, 62, 63 };

    int board[64] = {
            -1, -2, -3, -4, -5, -3, -2, -1,
            -6, -6, -6, -6, -6, -6, -6, -6,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            6, 6, 6, 6, 6, 6, 6, 6,
            1, 2, 3, 4, 5, 3, 2, 1 };

    void mainFunctions(int u);
};
