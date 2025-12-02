#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Character
{
public:
	Character(sf::Vector2f newSize, float newMoveSpeed)
	{
		hitbox.setSize(newSize);
		size = newSize;
		moveSpeed = newMoveSpeed;
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(hitbox);
	}

	void move(sf::Vector2f distance) {
		hitbox.move(distance);
	}

	// set the starting position of the character
	void setPosition(sf::Vector2f newPosition)
	{
		hitbox.setPosition(newPosition);
	}

	float getX() {
		return hitbox.getPosition().x;
	}

	float getY() {
		return hitbox.getPosition().y;
	}

	// getters
	sf::RectangleShape getHitbox() const { return hitbox; }
	sf::Vector2f getSize() const { return size; }
	float getMoveSpeed() const { return moveSpeed; }

	// setters
	void setSize(const sf::Vector2f newSize) 
	{
		hitbox.setSize(newSize);
		size = newSize;
	}
	void setMoveSpeed(const float newMoveSpeed) { moveSpeed = newMoveSpeed; }

protected:
	sf::RectangleShape hitbox;
	sf::Vector2f size;
	float moveSpeed;
};