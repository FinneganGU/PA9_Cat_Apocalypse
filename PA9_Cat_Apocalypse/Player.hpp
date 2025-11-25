#pragma once

#include "Character.hpp"

class Player : public Character
{
public:
	Player(sf::Vector2f size, float newMoveSpeed) : Character(size, newMoveSpeed)
	{
		isJumping = false;
		sf::Texture texture("Sprites/cat_nomf_flip");
		sf::Sprite player(texture);
	}

	void jump()
	{
		hitbox.move({ 0,50 });
		isJumping = true;
	}

private:
	bool isJumping;
};