#include <iostream>
#include "save.h"
#include <fstream>
#include "ChessBoard.h"

using namespace sf;
using namespace std;

void ChessBoard::loadTextures() {
    for (int i = 0; i < 64; i++) {
        if (spritePositions[i] == 0 || spritePositions[i] == 7)
            texture[i].loadFromFile("images/blackRook.png");
        if (spritePositions[i] == 1 || spritePositions[i] == 6)
            texture[i].loadFromFile("images/blackKnight.png");
        if (spritePositions[i] == 2 || spritePositions[i] == 5)
            texture[i].loadFromFile("images/blackBishop.png");
        if (spritePositions[i] == 3)
            texture[i].loadFromFile("images/blackQueen.png");
        if (spritePositions[i] == 4)
            texture[i].loadFromFile("images/blackKing.png");
        if (spritePositions[i] >= 8 and spritePositions[i] <= 15)
            texture[i].loadFromFile("images/blackPawn.png");
        if (spritePositions[i] == 63 || spritePositions[i] == 56)
            texture[i].loadFromFile("images/whiteRook.png");
        if (spritePositions[i] == 62 || spritePositions[i] == 57)
            texture[i].loadFromFile("images/whiteKnight.png");
        if (spritePositions[i] == 61 || spritePositions[i] == 58)
            texture[i].loadFromFile("images/whiteBishop.png");
        if (spritePositions[i] == 59)
            texture[i].loadFromFile("images/whiteQueen.png");
        if (spritePositions[i] == 60)
            texture[i].loadFromFile("images/whiteKing.png");
        if (spritePositions[i] >= 48 and spritePositions[i] <= 55)
            texture[i].loadFromFile("images/whitePawn.png");
    }
}

void ChessBoard::setBoard() {
    ifstream in, in2;
    in.open("spritePositions.txt");
    in2.open("boardPositions.txt");
    for (int j = 0; j < 64; j++) {
        int a, b;
        char c, d;
        in >> a >> c;
        spritePositions[j] = a;
        in2 >> b >> d;
        board[j] = b;
    }
    in >> turn;
    in.close();
    in2.close();
}

void ChessBoard::drawBoard(RenderWindow& window) {
    for (int j = 0; j < 64; ++j) {
        window.draw(rectangle[j]);
    }
    for (int j = 0; j < 64; ++j) {
        window.draw(sprite[j]);
    }
}

void ChessBoard::loadBoard() {
    for (int j = 0; j < 64; j++) {
        sprite[j].setTexture(texture[j]);
        rectangle[j].setSize(Vector2f(650 / 8.0f, 650 / 8.0f));
    }
    int counter = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            rectangle[counter].setPosition(j * rectangle[counter].getSize().y,
                i * rectangle[counter].getSize().x);
            sprite[counter].setPosition(j * rectangle[counter].getSize().y, i * rectangle[counter].getSize().x);
            if ((i + j) % 2 == 0) {
                rectangle[counter].setFillColor(Color::White);
            }
            else {
                Color c(160, 82, 45);
                rectangle[counter].setFillColor(c);
            }
            counter++;
        }
    }
}

void ChessBoard::clearBoard() {
    int counter = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                rectangle[counter].setFillColor(Color::White);
            }
            else {
                Color c(160, 82, 45);
                rectangle[counter].setFillColor(c);
            }
            counter++;
        }
    }
}

void ChessBoard::endGame(RenderWindow& window) {
    Save s;
    window.close();
    if (s.sMain()) {
        ofstream out, out2;
        out.open("spritePositions.txt");
        out2.open("boardPositions.txt");
        for (int i = 0; i < 64; i++) {
            out << spritePositions[i] << ",";
            out2 << board[i] << ",";
        }
        out << turn;
        out.close();
        out2.close();
    }
}

void ChessBoard::gripFigure(int j, Vector2i pos) {
    if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
        n = j;
        clearBoard();
        rectangle[n].setFillColor(Color::Red);
        if (spritePositions[n] != 64) {
            cap++;
        }
    }
}

void ChessBoard::makeMove(int j, int spritePos, RenderWindow& window) {
    turn++;
    cc = spritePositions[j];
    if (j != n) {
        sprite[spritePos].setPosition(secondPos);
        sprite[cc].setPosition(700, 700);
        spritePositions[j] = spritePositions[n];
        spritePositions[n] = 64;
        if (board[j] == BLACK_KING || board[j] == WHITE_KING) {
            endGame(window);
        }
        if (j <= 63 and j >= 56 and board[n] == BLACK_PAWN) {
            board[j] = BLACK_QUEEN;
        }
        else if (j >= 0 and j <= 7 and board[n] == WHITE_PAWN) {
            board[j] = WHITE_QUEEN;
        }
        else {
            board[j] = board[n];
            board[n] = FREE;
        }
        n = j;
    }
}

void ChessBoard::mainFunctions(int u) {
    RenderWindow window(VideoMode(650, 650), "The Chess");
    if (u == 0) {
        setBoard();
    }
    loadTextures();
    loadBoard();
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                endGame(window);
            }
            if (Mouse::isButtonPressed(Mouse::Right)) {
                for (int j = 0; j < 64; ++j) {
                    if ((turn % 2 == 0 && board[j] < 0) || (turn % 2 != 0 && board[j] > 0)) {
                        gripFigure(j, pos);
                    }
                }
            }
            if (cap != 0)
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                            isMove = box.identifier(n, j, board[n], board);
                            secondPos = rectangle[j].getPosition();
                            int spritePos = spritePositions[n];
                            if (isMove) {
                                makeMove(j, spritePos, window);
                            }
                            clearBoard();
                        }
                    }
                    cap = 0;
                }
        }
        window.clear();
        drawBoard(window);
        window.display();
    }
}