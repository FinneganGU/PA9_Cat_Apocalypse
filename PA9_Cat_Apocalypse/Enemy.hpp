#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"


class Enemy : public Character
{
public:
    Enemy(sf::Vector2f newSize, float newMoveSpeed);

    void update();  // update enemy movement
    void setPatrolBounds(float left, float right);  // set enemy patrols
    void setPatrolDistance(float distance);  // Set how far enemy moves before turning

private:
    int direction;  // 1 for right, -1 for left
    float patrolLeftBound;
    float patrolRightBound;
    float startingX;
    bool useBounds;  // Whether to use bounds or distance for patrol
    float patrolDistance;
    float maxDistanceFromStart;
};

#endif
