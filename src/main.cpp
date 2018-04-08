#include <iostream>
#include <SFML/Graphics.hpp>

#include "media.h"

int main() {
    load_media();

    sf::RenderWindow window(sf::VideoMode(500, 500), "test");

    while(window.isOpen()) {
        sf::Event e;
        if(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(sf::Sprite(gTextureManager.get("assets/cat.jpg")));
        window.display();
    }

    return 0;
}
