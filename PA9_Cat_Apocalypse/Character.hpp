#pragma once

#include <SFML/Graphics.hpp>

class Character
{
public:
	Character(sf::Vector2f size, float newMoveSpeed) {
		hitbox.setSize(size);
		moveSpeed = newMoveSpeed;
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(hitbox);
	}

	void move(sf::Vector2f distance) {
		hitbox.move(distance);
	}

	// set the starting position of the character
	void setPosition(sf::Vector2f newPosition) {
		hitbox.setPosition(newPosition);
	}

	int getX() {
		return hitbox.getPosition().x;
	}

	int getY() {
		return hitbox.getPosition().y;
	}

protected:
	sf::RectangleShape hitbox;
	float moveSpeed;
};