// "Copyright 2022 Emily Sheehan"

#include "CelestialBody.hpp"
#include <cmath>

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


void CelestialBody::updatePosition(double time) {
  xpos = xpos + xvel*time;
  ypos = ypos + yvel*time;

  double x = (1 +xpos/universe_radius) * window_radius;
  double y = ((1-ypos/universe_radius) * window_radius);
  sprite.setPosition(sf::Vector2f(x, y));
}

void CelestialBody::accelerate(CelestialBody &CB, double time) {
  double dx = CB.xpos - xpos;
  double dy = CB.ypos - ypos;
  double r2 = dx * dx + dy * dy;
  double r  = sqrt(r2);

  if (r == 0) {
    std::cout << "fdsfsd" << std::endl;
  }
  double force = ((6.67e-11)*CB.mass*mass) / r2;

  double forceX = force * (dx/r);
  double forceY = force * (dy/r);

  double accX = forceX / mass;
  double accY = forceY / mass;

  xvel = xvel + accX*time;
  yvel = yvel + accY*time;
}

std::ostream& operator<< (std::ostream &output, CelestialBody &CB) {
  output << "  " << CB.xpos << "  " << CB.ypos << "  " << CB.xvel << "  " << CB.yvel
   << "  " << CB.mass << "  " << CB.img_name; 

  return output;
}
