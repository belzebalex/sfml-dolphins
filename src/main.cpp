#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "gamelevel.hpp"

#define RADIANS_TO_DEGREES 57.269

using namespace std;


int main()
{ 
  sf::RenderWindow window(sf::VideoMode(800, 500), "SFML Alex");
	sf::View view ( sf::Vector2f(100, 100), sf::Vector2f(800, 500) );
  GameLevel gamelevel;	
 
 	while( window.isOpen() )
  {
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ))
      window.close();
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::P ))
			while(!sf::Keyboard::isKeyPressed( sf::Keyboard::O ));
		window.clear( sf::Color(100, 100, 255 ) );


		float linear = 3, angular = 0;
		if(sf::Keyboard::isKeyPressed( sf::Keyboard::Z ))
			angular = -2;
			
		if(sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
			angular = 2;
			
		gamelevel.update(linear, angular);
		
		window.draw( gamelevel );
		view.setCenter( gamelevel.getViewPosition() );
		window.setView( view );
		window.display();
  }

	return 0;
}
/*
int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Alex");
  window.setVerticalSyncEnabled(true);

  
  sf::Sprite alien_sprite;
  sf::Texture alien_texture;

  if (!alien_texture.loadFromFile("img/dolphin.png"))
  {
    cout << "Error loading texture" << endl;
  }

  alien_sprite.setTexture( alien_texture );


  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch( event.type ) 
      {
        case  sf::Event::Closed:
          window.close();
          break;
	 

        default:
          break;
      }
    }
	
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
	window.close();

    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    alien_sprite.setPosition(localPosition.x, localPosition.y);
    alien_sprite.setScale(sf::Vector2f(0.05f, 0.05f)); // absolute scale factor
    window.clear();
    window.draw( alien_sprite );
    window.display();
  }

  return 0;
}
*/
