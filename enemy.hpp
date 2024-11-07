#pragma once
#include "text.hpp"
class enemy
{
private:

    //LOOKS
    sf::Texture TextureEnemy;
    sf::Sprite SpriteEnemy;

    //COREthings

    void initSprite();
    void initTexture();
    //physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float velocityMaxY;
	//functions
    void initPhysics();
    void initVariables();
    //text
public:
    enemy();
    virtual ~enemy();
    //void updatePhysics();
    void renderText();
	void updateMovement(float DeltaTime);
    void update(float DeltaTime);
	const sf::Vector2f getPosition() const;
    void setPosition(const float x,const float y);
    void move(const float dir_x,const float dir_y);
    void render(sf::RenderTarget& target);
    //GameVariables;
    float health,healthlost;
    float damagedelt,damagetaken;
};


