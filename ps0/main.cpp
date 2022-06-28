//Emily Sheehan
//To move the sprite, use the arrow keys. To increase the sprites size, press the '.' key (period). To decrease its size, press the ',' (comma).

#include <SFML/Graphics.hpp>

int main()
{
        
    bool upArrowPressed=false;
    bool downArrowPressed=false;
    bool leftArrowPressed=false;
    bool rightArrowPressed=false;
    bool periodPressed=false;
    bool commaPressed=false;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Emily's Project 0");
    sf::CircleShape shape(80, 8);
    shape.setFillColor(sf::Color::Magenta);

    //values to set sprite postion
    int x_coord = window.getSize().x / 2;
    int y_coord = window.getSize().y / 2;

    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite(texture);
    sprite.setScale(.05,.05);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                // If escape is pressed, close the application
                case  sf::Keyboard::Escape : window.close(); break;

                //Handles the up, down, left,right, period, and comma key presses
                case sf::Keyboard::Up:
                    upArrowPressed=true;
                    break;
                case sf::Keyboard::Down:
                    downArrowPressed=true; 
                    break;
                case sf::Keyboard::Left:
                    leftArrowPressed=true; 
                    break;
                case sf::Keyboard::Right:
                    rightArrowPressed=true; 
                    break;
                case sf::Keyboard::Period:
                    periodPressed=true; 
                    break;
                case sf::Keyboard::Comma:
                    commaPressed=true; 
                    break;
                default : break;
                }
            }

            // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                //Handles the up, down, left,right, period, and comma key releases

                case sf::Keyboard::Up :     
                    upArrowPressed=false; 
                    break;
                case sf::Keyboard::Down:
                    downArrowPressed=false; 
                    break;
                case sf::Keyboard::Left:
                    leftArrowPressed=false;
                    break;
                case sf::Keyboard::Right:
                    rightArrowPressed=false;
                    break;
                case sf::Keyboard::Period:
                    periodPressed=false;
                    break;
                case sf::Keyboard::Comma:
                    commaPressed=false;
                    break;

                default : break;
                }
            }
        }
        //if key pressed...

        if (leftArrowPressed){
            x_coord -= 2;
        } 
        else if (rightArrowPressed){
            x_coord += 2;
        } 
        else if (upArrowPressed){
            y_coord -= 2;
        } 
        else if (downArrowPressed){
            y_coord += 2;
        } 
        else if(periodPressed){
            sprite.scale(1.01, 1.01);
        }
        else if(commaPressed){
            sprite.scale(.99, .99);
        }
        window.clear();

        sprite.setPosition(x_coord, y_coord);

        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}