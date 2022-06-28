// "Copyright 2022 Emily Sheehan"

#include "CelestialBody.hpp"

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)
const {
    target.draw(sprite);
}

CelestialBody::CelestialBody(double universe_radius, double window_radius)
: universe_radius(universe_radius), window_radius(window_radius) {
}

std::istream& operator>> (std::istream &input, CelestialBody &CB) {
  input >> CB.xpos >> CB.ypos;
  input >> CB.xvel >> CB.yvel;
  input >> CB.mass  >> CB.img_name;

  if (!CB.image.loadFromFile(CB.img_name)) {
      throw std::ios_base::failure("Couldn't load image");
  }

  CB.texture.loadFromImage(CB.image);

  CB.sprite.setTexture(CB.texture);

  double x = (1 + CB.xpos/CB.universe_radius) * CB.window_radius;
  double y =((1-CB.ypos/CB.universe_radius) * CB.window_radius);
  CB.sprite.setPosition(sf::Vector2f(x, y));

  return input;
}

std::ostream& operator<< (std::ostream &output, CelestialBody &CB) {
  output << "Name: " << CB.img_name << std::endl;
  output << "X Position: " << CB.xpos << std::endl;
  output << "Y Position: " << CB.ypos << std::endl;
  output << "X Velocity: " << CB.xvel << std::endl;
  output << "Y Velocity: " << CB.yvel << std::endl;
  output << "Mass: " << CB.mass << std::endl;

  return output;
}
