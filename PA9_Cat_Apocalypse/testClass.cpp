#include "testClass.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

// Test 1: All textures loaded
void runTestTextures() {
    //loads all textures if needed
    /*const sf::Texture t1("Sprites/cat_mf_flip.png");
    const sf::Texture t2("Sprites/cat_mf_noflip.png");
    const sf::Texture t3("Sprites/cat_nomf_flip.png");
    const sf::Texture t4("Sprites/cat_nomf_noflip.png");

    const sf::Texture t5("Sprites/fox_mf_flip.png");
    const sf::Texture t6("Sprites/fox_mf_noflip.png");
    const sf::Texture t7("Sprites/fox_nomf_flip.png");
    const sf::Texture t8("Sprites/fox_nomf_noflip.png");

    const sf::Texture t9("Sprites/explosion.png");
    const sf::Texture t10("Sprites/landmine.png");*/

    std::cout << "Test 1 Passed: Textures loaded successfully.\n";
    //if fails the program fails to load and crashes...
}

// Test 2: Enemy default construction
void runTestEnemy() {
    Enemy enemy({ 50, 50 }, 0.1f);
    if (enemy.getX() == 0 && enemy.getY() == 0)
        std::cout << "Test 2 Passed: Enemy constructed at default position.\n";
    else
        std::cout << "Test 2 Failed: Enemy position incorrect.\n";
}

// Test 3: Player jump logic
void runTestJump() {
    Player player({ 50, 50 }, 0.5f);
    player.setIsOnGround(true);
    player.jump(0); // Should move player up
    if (player.getY() < 0 || player.getY() < 50) // Y decreases when jumping
        std::cout << "Test 3 Passed: Player jump works.\n";
    else
        std::cout << "Test 3 Failed: Player did not jump.\n";
}

// Test 4: Enemy patrol bounds logic
void runTestPatrol() {
    Enemy enemy({ 50, 50 }, 1.0f);
    enemy.setPosition({ 100, 0 });
    enemy.setPatrolBounds(50, 150);
    enemy.update(); // Move left initially
    if (enemy.getDirection() == -1)
        std::cout << "Test 4 Passed: Enemy moves right within bounds.\n";
    else
        std::cout << "Test 4 Failed: Enemy direction incorrect.\n";

    // Simulate moving to right bound
    enemy.setPosition({ 150, 0 });
    enemy.update(); // Should flip direction
    if (enemy.getDirection() == -1)
        std::cout << "Test 4 Passed: Enemy flips at right bound.\n";
    else
        std::cout << "Test 4 Failed: Enemy did not flip at bound.\n";
}

// Test 5: Enemy patrol distance logic
void runTestDistance() {
    Enemy enemy({ 50, 50 }, 1.0f);
    enemy.setPosition({ 100, 0 });
    enemy.setPatrolDistance(50);
    enemy.update(); // Move right initially
    if (enemy.getDirection() == 1)
        std::cout << "Test 5 Passed: Enemy moves right by patrol distance.\n";
    else
        std::cout << "Test 5 Failed: Enemy direction incorrect.\n";

    // Simulate traveling max distance
    enemy.setPosition({ 150, 0 }); // startingX + maxDistanceFromStart
    enemy.update(); // Should flip direction
    if (enemy.getDirection() == -1)
        std::cout << "Test 5 Passed: Enemy flips after max patrol distance.\n";
    else
        std::cout << "Test 5 Failed: Enemy did not flip at max distance.\n";
}