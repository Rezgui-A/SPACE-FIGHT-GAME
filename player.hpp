#pragma once

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class player
{
    private:
    //LOOKS
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;

	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;
    //game
    float attackCooldown;
	float attackCooldownMax;
    //physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

    //COREthings
    void initVariables();
    void initSprite();
    void initTexture();
    void initAnimations();
    void initPhysics();

    public:
    //constructors/destructors
    player();
	virtual ~player();
    //Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();
    //accesosrs
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	//functions
	void resetAnimationTimer();
    void updateAnimations();
    void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
    void update();
	void render(sf::RenderTarget& target);

    //GameVariables;
    float health,healthlost;
    float damagedelt,damagetaken;

	const bool canAttack();

	void updateAttack();
};
