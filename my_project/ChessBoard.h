#pragma once
#include "utilityBox.h"
#include <SFML/Graphics.hpp>
constexpr int BLACK_ROOK = -1;
constexpr int BLACK_KNIGHT = -2;
constexpr int BLACK_BISHOP = -3;
constexpr int BLACK_QUEEN = -4;
constexpr int BLACK_KING = -5;
constexpr int BLACK_PAWN = -6;
constexpr int WHITE_ROOK = 1;
constexpr int WHITE_KNIGHT = 2;
constexpr int WHITE_BISHOP = 3;
constexpr int WHITE_QUEEN = 4;
constexpr int WHITE_KING = 5;
constexpr int WHITE_PAWN = 6;
constexpr int FREE = 0;
class ChessBoard {
private:
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
             BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK,
             BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN,
             FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
             FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
             FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
             FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
             WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN,
             WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK };
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
    sf::Vector2f secondPos;
    int cap = 0;

    void loadTextures();

    void loadBoard();

    void drawBoard(sf::RenderWindow& window);

    void endGame(sf::RenderWindow& window);

    void clearBoard();

    void gripFigure(int j, sf::Vector2i pos);

    void makeMove(int j, int spritePos, sf::RenderWindow& window);

public:
    void mainFunctions(int u);
    void setBoard();
};
