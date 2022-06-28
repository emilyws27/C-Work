// "Copyright 2022 Emily Sheehan"

#include "Universe.hpp"
#include "CelestialBody.hpp"


int main(int argc, char* argv[]) {
    std::string t = argv[1];
    std::string delta_t = argv[2];

    double t_double = std::stod(t);
    double td_double = std::stod(delta_t);
    double start = 0;

    std::cout << td_double << std::endl;

    Universe u;
    std::cin >> u;

    sf::RenderWindow w(sf::VideoMode(600, 600), "PS3a");
    sf::Image background;

    if (!background.loadFromFile("background.jpg")) {
        return -1;
    }

    sf::Texture text;
    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text time_;

    time_.setFont(font);

    time_.setCharacterSize(30);

    text.loadFromImage(background);

    sf::Sprite sprite;
    sprite.setTexture(text);


    while (w.isOpen()) {
        sf::Event event;

        while (w.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                w.close();
        }
        w.clear();
        w.draw(sprite);
        time_.setString("Elapsed Time (seconds): " + std::to_string(start));
        w.draw(time_);
        u.step(td_double);
        w.draw(u);
        w.display();

        start += td_double;

        if (start >= t_double) {
            //std::cout << " ...xpos...  ...ypos...  ...yvel...  ...mass...  filename" << std::endl;
            break;
        }

    }
    std::cout << u << std::endl;

}
