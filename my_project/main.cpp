#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "ChessBoard.h"

using namespace sf;
using namespace std;
Texture texture[8];
Sprite sprite[8];

int main() {
    RenderWindow window(VideoMode(650, 650), "The Chess");

    texture[0].loadFromFile("images/board.png");
    texture[1].loadFromFile("images/load-button.png");
    texture[2].loadFromFile("images/about.png");
    texture[3].loadFromFile("images/exit.png");
    texture[4].loadFromFile("images/play-button.png");
    texture[5].loadFromFile("images/about_the_game.png");
    texture[6].loadFromFile("images/back.png");
    texture[7].loadFromFile("images/note.png");

    for (int i = 0; i < 8; i++) {
        sprite[i].setTexture(texture[i]);
    }
    sprite[0].setScale(0.73f, 0.73f);
    sprite[0].setPosition(0, 0);
    sprite[1].setPosition(20, 140);
    sprite[2].setPosition(40, 240);
    sprite[3].setPosition(80, 330);
    sprite[4].setPosition(45, 50);
    sprite[5].setPosition(1000, 1000);
    sprite[6].setPosition(1000, 1000);
    sprite[7].setPosition(1000, 1000);

    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (sprite[4].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    ChessBoard graphics;
                    graphics.mainFunctions(1);
                }
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    ChessBoard graphics;
                    graphics.mainFunctions(0);
                }
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    sprite[1].setPosition(1000, 1000);
                    sprite[2].setPosition(1000, 1000);
                    sprite[3].setPosition(1000, 1000);
                    sprite[4].setPosition(1000, 1000);
                    sprite[5].setPosition(0, 40);
                    sprite[6].setPosition(20, 320);
                    sprite[7].setPosition(420, 595);
                }
                if (sprite[3].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                }
                if (sprite[6].getGlobalBounds().contains(pos.x, pos.y)) {
                    sprite[1].setPosition(20, 140);
                    sprite[2].setPosition(40, 240);
                    sprite[3].setPosition(80, 330);
                    sprite[4].setPosition(45, 50);
                    sprite[5].setPosition(1000, 1000);
                    sprite[6].setPosition(1000, 1000);
                    sprite[7].setPosition(1000, 1000);
                }
            }
        }

        window.clear();
        for (int i = 0; i < 8; i++) {
            window.draw(sprite[i]);
        }
        window.display();
    }
    return 0;
}