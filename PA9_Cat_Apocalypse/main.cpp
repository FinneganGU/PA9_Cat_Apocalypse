#include "Character.hpp"
#include "Player.hpp"
#include "testScreen.hpp"

sf::Vector2f defaultPosition = { 1920/2, 450 };

int main()
{
    // load textures
    const sf::Texture t1("Sprites/cat_mf_flip.png");
    const sf::Texture t2("Sprites/cat_mf_noflip.png");
    const sf::Texture t3("Sprites/cat_nomf_flip.png");
    const sf::Texture t4("Sprites/cat_nomf_noflip.png");

    const sf::Texture t5("Sprites/fox_mf_flip.png");
    const sf::Texture t6("Sprites/fox_mf_noflip.png");
    const sf::Texture t7("Sprites/fox_nomf_flip.png");
    const sf::Texture t8("Sprites/fox_nomf_noflip.png");

    const sf::Texture t9("Sprites/explosion.png");
    const sf::Texture t10("Sprites/landmine.png");

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!");
    //window.setKeyRepeatEnabled(true);

        // output to screen first
    if (!runTestScreen(window))
        return 0;       // user closed window early

    Player player({ 50,50 }, 0.5);
    player.setPosition(defaultPosition);
    player.getHitbox().setTexture(&t3);

    const int groundHeight = 500;
    const float gravitySpeed = 0.5;

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.jump();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.setDirection(-1);
            player.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.setDirection(1);
            player.moveRight();
        }
        else
        {
            player.setDirection(0);
        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (player.getY() < groundHeight)
        {
            player.move({ 0,gravitySpeed });
        }
        else if (player.getY() == groundHeight)
        {
            player.setIsOnGround(true);
        }

        if (player.getX() > 1920 || player.getX() < 0)
        {
            player.setPosition(defaultPosition);
        }
        
        window.clear();
        player.drawTo(window);
        window.display();
    }
    return 0;
}