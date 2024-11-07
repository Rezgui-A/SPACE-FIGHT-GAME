#pragma once

#include "player.hpp"
#include "enemy.hpp"
#include "text.hpp"
#include "bullet.hpp"
class game{
private:
    //window rendering names
    sf::RenderWindow* window;
	sf::VideoMode videoMode;

    //player info
	player* Player;
	enemy* Enemy;
    text* Text;
    //private functions
    void windowCreate();
    void initbackground();
    sf::Sprite background;
    sf::Texture backgroundTexture;
    //player functions
    void initPlayer();
    void initEnemy();
    void initText();
	void initTextures();
	std::map<std::string, sf::Texture*> textures;

    //bullets
    std::vector<Bullet*> bullets;
public:
    //initialising the private functions in class game in main.cpp
    game();
    virtual ~game();
    sf::Event ev;
    //player
    void renderPlayer();
    void renderEnemy();
    void renderText();
    void updatePlayer();
    void updateEnemy(float deltatime);
    void updateCollision();
    //game state
    const bool GetGameRunning() const;
    bool pause=false;
    const bool GetGameEnd() const;
    void render();
    void update();
    void resume();
	const sf::RenderWindow& getWindow() const;

	//game update
    void updateBullets();
};
