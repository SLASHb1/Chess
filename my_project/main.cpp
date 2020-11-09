#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;
const float width = 650;
const float height = 650;
Texture texture[3];
Sprite sprite[3];
RectangleShape rectangle;

int main() {
    RenderWindow window(VideoMode(width, height), "Chess");
    texture[0].loadFromFile("images/play-button.png");
    texture[1].loadFromFile("images/refresh-button.png");
    texture[2].loadFromFile("images/board.png");
 
    rectangle.setSize(Vector2f(width, height));
    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[2].setScale(0.73f, 0.73f);
    sprite[0].setPosition(55, 60);
    sprite[1].setPosition(30, 160);
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
                    /*...*/
                }
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    /*...*/
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
    return 0;
}
