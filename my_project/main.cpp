#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "ChessBoard.h"

using namespace sf;
Texture texture[3];
Sprite sprite[3];
RectangleShape rectangle;

int main() {
    RenderWindow window(VideoMode(650, 650), "Chess The Game Of Kings!");

    texture[0].loadFromFile("images/play-button.png");
    texture[1].loadFromFile("images/refresh-button.png");
    texture[2].loadFromFile("images/board.png");

    rectangle.setSize(Vector2f(650, 650));
    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[2].setScale(0.73f, 0.73f);
    sprite[0].setPosition(65, 60);
    sprite[1].setPosition(40, 140);
    sprite[2].setPosition(0, 0);
    rectangle.setFillColor(Color::White);

    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left)) {
                if (sprite[0].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    ChessBoard graphics;
                    graphics.mainFunctions(1);
                }
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
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
                    ChessBoard graphics;
                    graphics.mainFunctions(0);
                }
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(sprite[2]);
        window.draw(sprite[0]);
        window.draw(sprite[1]);
        window.display();
    }
}
