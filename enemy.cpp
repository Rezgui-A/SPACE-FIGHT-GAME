#include "includes.hpp"
#include "enemy.hpp"

void enemy::initVariables()
{
     this->health = 8000;
}

void enemy::initTexture()
{
	if (!this->TextureEnemy.loadFromFile("Textures/enemy.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the enemy sheet!" << "\n";
	}
}
void enemy::initSprite()
{
	this->SpriteEnemy.setTexture(this->TextureEnemy);
	//this->currentFrame = sf::IntRect(0, 0, 40, 50); //SHOULD BE 40 50

	//this->sprite.setTextureRect(this->currentFrame);
	this->SpriteEnemy.setScale(0.25, 0.25);
	this->SpriteEnemy.setRotation(90.f);
	this->SpriteEnemy.setPosition(200,200);

}



void enemy::render(sf::RenderTarget & target)
{
	target.draw(this->SpriteEnemy);
	sf::CircleShape circ;
	circ.setFillColor(sf::Color::Blue);
	circ.setRadius(2.f);
	circ.setPosition(this->SpriteEnemy.getPosition());
	target.draw(circ);
}
void enemy::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}
void enemy::setPosition(const float x, const float y)
{
	this->SpriteEnemy.setPosition(x, y);
}

const sf::Vector2f enemy::getPosition() const
{
	return this->SpriteEnemy.getPosition();
}
void enemy::initPhysics()
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 0.4f;
	this->velocityMaxY = 15.f;
}
void enemy::updateMovement(float DeltaTime)
{
    this->SpriteEnemy.move(1,0);
}
void enemy::update(float DeltaTime)
{
    this->updateMovement(DeltaTime);
}
enemy::enemy()
{
    this->initTexture();
    this->initSprite();
    this->initPhysics();
    this->initVariables();
}

enemy::~enemy()
{
}
