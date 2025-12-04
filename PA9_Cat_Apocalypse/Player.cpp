#include "Player.hpp"

Player::Player(sf::Vector2f newSize, float newMoveSpeed) : Character(newSize, newMoveSpeed)
{
	direction = 0;
	isOnGround = false;
}

void Player::jump(int frameCount)
{
	if (isOnGround == true || frameCount <= 200)
	{
		hitbox.move({ direction * moveSpeed * 2, -(moveSpeed * 5) });
		isOnGround = false;
	}
}

void Player::moveLeft()
{
	if (isOnGround = true)
	{
		hitbox.move({ -moveSpeed, 0 });
	}
}

void Player::moveRight()
{
	if (isOnGround = true)
	{
		hitbox.move({ moveSpeed, 0 });
	}
}