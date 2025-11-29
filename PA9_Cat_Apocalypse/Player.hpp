#pragma once

#include "Character.hpp"

class Player : public Character
{
public:
	Player(sf::Vector2f newSize, float newMoveSpeed) : Character(newSize, newMoveSpeed)
	{
		/*sf::Texture texture("cat_nomf_flip.png");
		sf::Sprite player(texture);*/
	}

	void jump()
	{
		if (onGround = true)
		{
			hitbox.move({ 0, -moveSpeed });
			onGround = false;
		}
	}

	void moveLeft()
	{
		if(onGround = true)
		{
			move({ -moveSpeed, 0 });
		}
	}

	void moveRight()
	{
		if (onGround = true)
		{
			move({ moveSpeed, 0 });
		}
	}

private:
	sf::Texture texture;
};