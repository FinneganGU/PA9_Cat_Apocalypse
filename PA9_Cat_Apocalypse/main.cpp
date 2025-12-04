#include "Character.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "testScreen.hpp"
#include "testClass.hpp"

int main()
{
    //test code for 5 total tests
    runTestTextures();
    runTestEnemy();
    runTestJump();
    runTestPatrol();
    runTestDistance();

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
    window.setKeyRepeatEnabled(false);

    // output to screen first
    if (!runTestScreen(window))
        return 0;       // user closed window early

    sf::Vector2f defaultPosition = { 1920 / 2, 450 };
    const int groundHeight = 500;
    const float gravitySpeed = 0.5;
    int frameCount = 0;

    Player player({ 50,50 }, 0.5);
    player.setPosition(defaultPosition);
    player.getHitbox().setTexture(&t3);

    //bullet components
    float bulletDir = 1.f;
    bool active = false;
    sf::Vector2f playerOffset = { 60.f, 25.f };
    float velocity = 1000.f;
    float radius = 10.f;
    sf::CircleShape bullet(radius);
    bullet.setOrigin({ radius, radius });
    bullet.setPosition(player.getHitbox().getPosition() + playerOffset);

    // Create enemy
    Enemy enemy({ 50, 50 }, 0.2);  // Enemy 
    enemy.setPosition({ 300, 500 });  // Start position
    enemy.getHitbox().setFillColor(sf::Color::Red);  // Make enemy visible (color dosen't work)
    enemy.setPatrolBounds(0, 1920);  // Patrol

    //gameclock
    sf::Clock gameClock;
    sf::Clock gameClock2;
    sf::Font font("C:/Windows/Fonts/arial.ttf");

    sf::Text timerText(font);
    timerText.setCharacterSize(48);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition({ 50,50 });
    //

    while (window.isOpen())
    {
        frameCount++;

        float dt = gameClock2.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.jump(frameCount);
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

        //bullet logic
        if (!active && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            active = true;
            if (player.getDirection() == 0)
            {
                bulletDir = 1;
            }
            else if(player.getDirection() == 1)
            {
                bulletDir = 1;
            }
            else
            {
                bulletDir = -1;
            }
            bullet.setPosition({ player.getHitbox().getPosition() + playerOffset });
        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //additional bullet logic
        if (active)
        {
            bullet.move({ velocity * bulletDir * dt, 0.f });

            if (bullet.getPosition().x >= 1920.f + radius || bullet.getPosition().x < -radius)
            {
                active = false;
            }
        }

        if (player.getY() < groundHeight)
        {
            player.move({ 0,gravitySpeed });
        }
        else if (player.getY() == groundHeight)
        {
            player.setIsOnGround(true);
            frameCount = 0;
        }

        //player collision template
        //the empty field inside findIntersection() should 
        if (enemy.getHitbox().getGlobalBounds().findIntersection(bullet.getGlobalBounds()))
        {
            enemy.setPosition({ 0,500 });
        }
        // Update enemy position
        enemy.update();
        // Check collision with enemy
        if (player.getHitbox().getGlobalBounds().findIntersection(enemy.getHitbox().getGlobalBounds()))
        {
            // Reset player position on collision
               //timer victory - changed to game over screen
            sf::Text victory(font);
            victory.setCharacterSize(80);
            victory.setFillColor(sf::Color::Red);
            victory.setString("Game Over");
            victory.setPosition({ 700,400 });

            while (window.isOpen())
            {
                while (const std::optional event = window.pollEvent())
                    if (event->is<sf::Event::Closed>()) window.close();

                window.clear();
                window.draw(victory);
                window.display();
            }
            //

            return 0;
        }

        //screen collision
        //Left side collision
        if (player.getX() < 0.f)
        {
            player.setPosition(sf::Vector2f(0.f, player.getY()));
        }

        //top side collision
        if (player.getY() < 0.f)
        {
            player.setPosition(sf::Vector2f(player.getX(), 1.f));
        }

        //right side collision
        if (player.getX() + player.getHitbox().getSize().x > 1920.f)
        {
            player.setPosition(sf::Vector2f(1920.f - player.getHitbox().getSize().x, player.getY()));
        }

        //timer clock update
        float elapsed = gameClock.getElapsedTime().asSeconds();

        timerText.setString("Time: " + std::to_string((int)elapsed));

        if (elapsed >= 60.f)
        {
            break; // jump to victory screen
        }
        //

        window.clear();
        //killing loose bullets
        if (active)
        {
            window.draw(bullet);
        }
        player.drawTo(window);
        enemy.drawTo(window);  // Draw the enemy
        window.draw(timerText); // draw timer to screen
        window.display();
    }

    //timer victory 
    sf::Text victory(font);
    victory.setCharacterSize(80);
    victory.setFillColor(sf::Color::Yellow);
    victory.setString("VICTORY!");
    victory.setPosition({ 700,400 });

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>()) window.close();

        window.clear();
        window.draw(victory);
        window.display();
    }
    //

    return 0;
}