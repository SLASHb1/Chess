#include <SFML/Graphics.hpp>
#include <iostream>
#include "utilityBox.h"
#include "save.h"
#include <fstream>

using namespace sf;
using namespace std;
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

class ChessBoard {
public:
    void loadTextures(Texture* texture);

    void loadBoard(Texture* texture, RectangleShape* rectangle, Sprite* sprite);

    void mainFunctions(int u);
};

void ChessBoard::loadTextures(Texture* texture) {
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

void ChessBoard::loadBoard(Texture* texture, RectangleShape* rectangle, Sprite* sprite) {
    for (int j = 0; j < 64; j++) {
        sprite[j].setTexture(texture[j]);
        sprite[j].setScale(1.7f, 1.7f);
    }
    for (int j = 0; j < 64; ++j) {
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

void ChessBoard::mainFunctions(int u) {
    RenderWindow window(VideoMode(650, 650), "Chess The Game Of Kings!");
    RectangleShape rectangle[64];
    Texture texture[65];
    Sprite sprite[65];
    loadTextures(texture);
    loadBoard(texture, rectangle, sprite);
    Identity box;
    bool isMove;
    float dx = 0, dy = 0;
    Vector2f oldPos, newPos;
    int n;
    int cc, turn = 1;
    int alliance, position;
    Vector2f firstPos, secondPos;
    int v;
    int q[64];
    static int cap = 0;
    for (int j = 0; j < 64; ++j) {
        q[j] = 64;
    }
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                save s;
                window.close();
                if (s.sMain()) {
                    ofstream out, out2;
                    out.open("spritePositions.txt");
                    out2.open("boardPositions.txt");
                    for (int i = 0; i < 64; i++) {
                        out << spritePositions[i] << ",";
                        out2 << board[i] << ",";
                    }
                    out.close();
                    out2.close();
                }
            }
            if (u != 0) {
                if (Mouse::isButtonPressed(Mouse::Right)) {
                    for (int j = 0; j < 64; ++j) {
                        if (turn % 2 == 0 and board[j] < 0) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                n = j;
                                firstPos = rectangle[j].getPosition();
                                v = spritePositions[j];
                                rectangle[n].setFillColor(Color::Red);
                                if (spritePositions[n] != 64) {
                                    cap++;
                                }
                            }
                        }
                    }
                    for (int j = 0; j < 64; ++j) {
                        if (turn % 2 != 0 and board[j] > 0) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                n = j;
                                firstPos = rectangle[j].getPosition();
                                v = spritePositions[j];
                                rectangle[n].setFillColor(Color::Red);
                                if (spritePositions[n] != 64) {
                                    cap++;
                                }
                            }
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
                                    turn++;
                                    cc = q[j] = spritePositions[j];
                                    if (j != n) {
                                        sprite[spritePos].setPosition(secondPos);
                                        sprite[cc].setPosition(100000000, 100000000);
                                        int suppose = spritePositions[j];
                                        spritePositions[j] = spritePositions[n];
                                        spritePositions[n] = 64;
                                        if (board[j] == -5 || board[j] == 5) {
                                            save s;
                                            window.close();
                                            if (s.sMain()) {
                                                ofstream out, out2;
                                                out.open("spritePositions.txt");
                                                out2.open("boardPositions.txt");
                                                for (int i = 0; i < 64; i++) {
                                                    out << spritePositions[i] << ",";
                                                    out2 << board[i] << ",";
                                                }
                                                out.close();
                                                out2.close();
                                            }
                                        }
                                        if (j <= 63 and j >= 56 and board[n] == -6) {
                                            board[j] = -4;
                                        }
                                        else if (j >= 0 and j <= 7 and board[n] == 6) {
                                            board[j] = 4;
                                        }
                                        else {
                                            board[j] = board[n];
                                            board[n] = 0;
                                        }
                                        n = j;
                                    }
                                }
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
                        }
                        cap = 0;
                    }
            }
        }
        window.clear();
        for (int j = 0; j < 64; ++j)
            window.draw(rectangle[j]);
        for (int j = 0; j < 65; j++) {
            if (q[j] == 64)
                window.draw(sprite[j]);
        }
        window.display();
    }
}
