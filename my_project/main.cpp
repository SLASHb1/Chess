#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "ChessBoard.h"

using namespace sf;
Texture texture[8];
Sprite sprite[8];
RectangleShape rectangle;

int main() {
    RenderWindow window(VideoMode(650, 650), "The Chess");
    
    texture[0].loadFromFile("images/play-button.png");
    texture[1].loadFromFile("images/refresh-button.png");
    texture[2].loadFromFile("images/about.png");
    texture[3].loadFromFile("images/exit.png");
    texture[4].loadFromFile("images/board.png");
    texture[5].loadFromFile("images/about_the_game.png");
    texture[6].loadFromFile("images/back.png");
    texture[7].loadFromFile("images/note.png");

    rectangle.setSize(Vector2f(650, 650));
    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[3].setTexture(texture[3]);
    sprite[4].setTexture(texture[4]);
    sprite[5].setTexture(texture[5]);
    sprite[6].setTexture(texture[6]);
    sprite[7].setTexture(texture[7]);
    sprite[4].setScale(0.73f, 0.73f);
    sprite[0].setPosition(45, 50);
    sprite[1].setPosition(20, 140);
    sprite[2].setPosition(40, 240);
    sprite[3].setPosition(80, 330);
    sprite[4].setPosition(0, 0);
    sprite[5].setPosition(1000, 1000);
    sprite[6].setPosition(1000, 1000);
    sprite[7].setPosition(1000, 1000);
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
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    sprite[0].setPosition(1000, 1000);
                    sprite[1].setPosition(1000, 1000);
                    sprite[2].setPosition(1000, 1000);
                    sprite[3].setPosition(1000, 1000);
                    sprite[5].setPosition(0, 40);
                    sprite[6].setPosition(20, 320);                  
                    sprite[7].setPosition(420, 595);                  
                }
                if (sprite[3].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();                  
                }
                if (sprite[6].getGlobalBounds().contains(pos.x, pos.y)) {
                    sprite[0].setPosition(45, 50);
                    sprite[1].setPosition(20, 140);
                    sprite[2].setPosition(40, 240);
                    sprite[3].setPosition(80, 330);
                    sprite[5].setPosition(1000, 1000);
                    sprite[6].setPosition(1000, 1000);
                    sprite[7].setPosition(1000, 1000);
                }
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(sprite[4]);
        window.draw(sprite[0]);
        window.draw(sprite[1]);
        window.draw(sprite[2]);
        window.draw(sprite[3]);
        window.draw(sprite[5]);
        window.draw(sprite[6]);
        window.draw(sprite[7]);
        window.display();
    }
    return 0;
}
