#include "testScreen.hpp"

bool runTestScreen(sf::RenderWindow& window)
{
    // Prepare button
    sf::RectangleShape button({ 200.f, 100.f });
    button.setOrigin(button.getSize() / 2.f);
    button.setPosition({ window.getSize().x / 2.f, window.getSize().y / 2.f });
    button.setFillColor(sf::Color(0, 170, 255));

    // Load font
    sf::Font font("C:/Windows/Fonts/arial.ttf");

    // Prepare text
    sf::Text text(font);
    text.setString("");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition({200,150});

    // 3 messages
    std::vector<std::string> messages{
        "Welcome to the game of Cat Apocalypse\n\n Click the button below to continue...",
        "Press the W key to jump\nPress the A key to move left\nPress the D key to move right\nPress the Space bar to shoot",
        "Objective: survive for 60 seconds! \n\nGame starting"
    };

    int index = 0;
    text.setString(messages[index]);

    bool mouseHeld = false;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                return false;
        }

        // Mouse handling (SFML 3 version)
        bool mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

        auto mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        bool hovering = button.getGlobalBounds().contains(mousePos);

        if (hovering)
            button.setFillColor(sf::Color::Yellow);
        else
            button.setFillColor(sf::Color(0, 170, 255));

        // Click event detection (on press and NOT previously held)
        if (mouseDown && !mouseHeld && hovering)
        {
            index++;

            // Finished all messages
            if (index >= messages.size())
                return true;

            text.setString(messages[index]);
        }

        mouseHeld = mouseDown;

        // Draw everything
        window.clear(sf::Color(64, 64, 64));
        window.draw(button);
        window.draw(text);
        window.display();
    }

    return false;
}
