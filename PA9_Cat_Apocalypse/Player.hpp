#pragma once

#include "Character.hpp"

class Player : public Character
{
public:
	Player(sf::Vector2f newSize, float newMoveSpeed);

	// movement controls
	void jump(int frameCount);
	void moveLeft();
	void moveRight();

	// getters
	bool getIsOnGround() const { return isOnGround; }
	int getDirection() const { return direction; }

	// setters
	void setIsOnGround(const bool newIsOnGround) { isOnGround = newIsOnGround; }
	void setDirection(const int newDirection) { direction = newDirection; }

private:
	bool isOnGround;
	int direction;
};