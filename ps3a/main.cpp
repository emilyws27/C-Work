// "Copyright 2022 Emily Sheehan"

#include "Universe.hpp"
#include "CelestialBody.hpp"


int main(int argc, char* argv[]) {
    Universe u;
    std::cin >> u;

    sf::RenderWindow w(sf::VideoMode(600, 600), "PS3a");
    sf::Image background;

    if (!background.loadFromFile("background.jpg")) {
        return -1;
    }

    sf::Texture text;
    text.loadFromImage(background);

    sf::Sprite sprite;
    sprite.setTexture(text);


    while (w.isOpen()) {
        sf::Event event;

        while (w.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                w.close();
            w.draw(sprite);
            w.draw(u);
            w.display();
        }
    }
}
