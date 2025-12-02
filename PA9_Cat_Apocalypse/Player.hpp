#pragma once

#include "Character.hpp"

class Player : public Character
{
public:
	Player(sf::Vector2f newSize, float newMoveSpeed) : Character(newSize, newMoveSpeed)
	{
		direction = 0;
		isOnGround = true;
	}

	void jump()
	{
		if (isOnGround = true)
		{
			hitbox.move({ direction * moveSpeed, -(moveSpeed * 5)});
			isOnGround = false;
		}
	}

	void moveLeft()
	{
		if(isOnGround = true)
		{
			hitbox.move({ -moveSpeed, 0 });
		}
	}

	void moveRight()
	{
		if (isOnGround = true)
		{
			hitbox.move({ moveSpeed, 0 });
		}
	}

	bool getIsOnGround() const { return isOnGround; }
	int getDirection() const { return direction; }

	void setIsOnGround(const bool newIsOnGround) { isOnGround = newIsOnGround; }
	void setDirection(const int newDirection) { direction = newDirection; }

private:
	bool isOnGround;
	int direction;
};