#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Save.h"

using namespace sf;

bool Save::sMain() {
    RenderWindow window(VideoMode(650, 650), "The Chess");
    Texture texture[3];
    Sprite sprite[3];
    texture[0].loadFromFile("images/board.png");
    texture[1].loadFromFile("images/savePos.png");
    texture[2].loadFromFile("images/trashTalk.png");
    sprite[0].setTexture(texture[0]);
    sprite[0].setScale(0.73f, 0.73f);
    sprite[0].setPosition(0, 0);
    sprite[1].setTexture(texture[1]);
    sprite[1].setPosition(20, 270);
    sprite[2].setTexture(texture[2]);
    sprite[2].setPosition(5, 10);
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left)) {
                if (sprite[0].getGlobalBounds().contains(pos.x, pos.y)) {
                    return true;
                    window.close();
                }
            }
        }
        window.clear();
        for (int i = 0; i < 3; i++) {
            window.draw(sprite[i]);
        }
        window.display();
    }
    return false;
}
