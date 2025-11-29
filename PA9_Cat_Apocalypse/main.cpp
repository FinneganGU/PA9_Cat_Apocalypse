#include "Player.hpp"

int main()
{
    system("cd");
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!");
    window.setKeyRepeatEnabled(true);
    //sf::Texture texture("cat_nomf_flip.png"); // fix sprites not appearing
    //sf::Sprite player(texture);
    Player player({ 50,50 }, 0.5);
    player.setPosition({ 700,500 });

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
            player.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.moveRight();
        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (player.getY() < groundHeight && !player.isOnGround())
        {
            player.move({ 0,gravitySpeed });
        }
        else if (player.getY() >= groundHeight)
        {
            player.setOnGround(true);
        }
        
        window.clear();
        player.drawTo(window);
        //window.draw(player);
        window.display();
    }
    return 0;
}