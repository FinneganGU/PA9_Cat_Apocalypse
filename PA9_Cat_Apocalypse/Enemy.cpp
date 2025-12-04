#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f newSize, float newMoveSpeed)
    : Character(newSize, newMoveSpeed)
{
    direction = 1;
    patrolLeftBound = 0;
    patrolRightBound = 0;
    startingX = 0;
    useBounds = false;
    patrolDistance = 100.0;
    maxDistanceFromStart = 0;
}

int Enemy::getDirection(Enemy direction) {
    return direction.direction;
}

void Enemy::update()
{
    // Move the enemy based on direction
    float moveAmount = direction * moveSpeed;
    move({ moveAmount, 0 });

    // bounds for patrol
    if (useBounds)
    {
        // right bound
        if (direction == 1 && getX() + getSize().x >= patrolRightBound)
        {
            direction = -1;  // Turn left
        }
        // left bound
        else if (direction == -1 && getX() <= patrolLeftBound)
        {
            direction = 1;   // Turn right
        }
    }
    // distance from starting point for patrol
    else
    {
        // Track maximum distance from starting point
        float currentDistance = getX() - startingX;

        // Check if traveled the patrol distance to the right
        if (direction == 1 && currentDistance >= maxDistanceFromStart)
        {
            direction = -1;  // Turn left
        }
        // Check if traveled the patrol distance to the left
        else if (direction == -1 && currentDistance <= -maxDistanceFromStart)
        {
            direction = 1;   // Turn right
        }
    }
}

void Enemy::setPatrolBounds(float left, float right)
{
    patrolLeftBound = left;
    patrolRightBound = right;
    startingX = getX();  // Use current position as starting point
    useBounds = true;
}

void Enemy::setPatrolDistance(float distance)
{
    patrolDistance = distance;
    maxDistanceFromStart = patrolDistance;
    startingX = getX();  // Use current position as starting point
    useBounds = false;
}
