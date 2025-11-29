#pragma once

#include <SFML/Graphics.hpp>

class Character
{
public:
	Character(sf::Vector2f newSize, float newMoveSpeed) {
		hitbox.setSize(newSize);
		hitbox.setFillColor(sf::Color::Blue);
		moveSpeed = newMoveSpeed;
		onGround = true;
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

	float getMoveSpeed() { return moveSpeed; }

	bool isOnGround() {
		return onGround;
	}

	void setOnGround(bool newOnGround)
	{
		onGround = newOnGround;
	}

protected:
	sf::RectangleShape hitbox;
	float moveSpeed;
	bool onGround;
};