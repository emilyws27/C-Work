#include "FibLFSR.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <bitset>

void transform(sf::Image &img, FibLFSR *fib);

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 4){
        cout << "incorrect number of arguments-- should be 4" << endl;
        return -1;
    }

    string input_file = argv[1];
    string output_file = argv[2];
    string password = argv[3];
    string FibLFSR_seed;

    for(char& c : password){
        FibLFSR_seed += bitset<8>(c).to_string();
    }

    cout<<FibLFSR_seed<< endl;


    FibLFSR fib(FibLFSR_seed);
    sf::Image img_input;

    if (!img_input.loadFromFile(input_file))
    {
        return -2;
    }
    
    sf::Image img_output = img_input;


    transform(img_output, &fib);

    sf::RenderWindow window_input(sf::VideoMode(img_input.getSize().x, img_input.getSize().y), "Input");
    sf::RenderWindow window_output(sf::VideoMode(img_output.getSize().x, img_output.getSize().y), "Output");

    sf::Texture texture_input;
    texture_input.loadFromImage(img_input);
    sf::Texture texture_output;
    texture_output.loadFromImage(img_output);

    sf::Sprite sprite_input;
    sprite_input.setTexture(texture_input);
    sf::Sprite sprite_output;
    sprite_output.setTexture(texture_output);

    while (window_input.isOpen() && window_output.isOpen())
    {
        sf::Event event;
        while (window_input.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_input.close();
        }
        while (window_output.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_output.close();
        }
        window_input.clear();
        window_input.draw(sprite_input);
        window_input.display();
        window_output.clear();
        window_output.draw(sprite_output);
        window_output.display();
    }

    if(!img_output.saveToFile(output_file)){
        cout << "could not save to file" << endl;
        return -3;
    }
        

    return 0;

}

void transform(sf::Image &img, FibLFSR *fib)
{
    sf::Color p;
    sf::Vector2u size = img.getSize();
    vector<bool> fib_vector = fib->get_fib_vector();

    for (unsigned int x = 0; (x < size.x); x++)
    {
        for (unsigned int y = 0; (y  < size.y); y++)
        {
            p = img.getPixel(x, y);

            p.r = p.r ^ fib->generate(15);
            p.g = p.g ^ fib->generate(15);
            p.b = p.b ^ fib->generate(15);

            img.setPixel(x, y, p);
        }
    }
}