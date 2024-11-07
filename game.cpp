#include "includes.hpp"
#include "game.hpp"

#ifndef GL_SRGB8_ALPHA8
#define GL_SRGB8_ALPHA8 0x8C43
#endif

void game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}
}
void game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void game::windowCreate()
{
    this->videoMode.height = 900;
	this->videoMode.width = 1600;
    this->window = new sf::RenderWindow (this->videoMode, "GAME",sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
}

void game::initbackground()
{
    bool sRgb = false;
    this->backgroundTexture.setSrgb(sRgb);
    if (!this->backgroundTexture.loadFromFile("Textures/background.jpg"))
        std::cout<<"Error Loading Background"<<"\n";
    this->background.setTexture(this->backgroundTexture);
    background.scale((float) this->window->getSize().x / backgroundTexture.getSize().x,(float) this->window->getSize().y / backgroundTexture.getSize().y);
}
const bool game::GetGameRunning() const
{
        return this->window->isOpen();
}
void game::initEnemy()
{
   	this->Enemy = new enemy();
}
void game::initPlayer()
{
	this->Player = new player();
}

void game::renderPlayer()
{
	this->Player->render(*this->window);
}
void game::renderEnemy()
{
	this->Enemy->render(*this->window);
}

void game::updatePlayer()
{
	this->Player->update();
}
void game::updateEnemy(float deltatime)
{
	this->Enemy->update(deltatime);
}
void game::updateCollision()
{
	//Left world collision
	if (this->Player->getGlobalBounds().left < 0.f)
	{
		this->Player->setPosition(0.f, this->Player->getGlobalBounds().top);
	}
	//Right world collison
	else if (this->Player->getGlobalBounds().left + this->Player->getGlobalBounds().width >= this->window->getSize().x)
	{
		this->Player->setPosition(this->window->getSize().x - this->Player->getGlobalBounds().width, this->Player->getGlobalBounds().top);
	}

	//Top world collision
	if (this->Player->getGlobalBounds().top < 0.f)
	{
		this->Player->setPosition(this->Player->getGlobalBounds().left, 0.f);
	}
	//Bottom world collision
	else if (this->Player->getGlobalBounds().top + this->Player->getGlobalBounds().height >= this->window->getSize().y)
	{
		this->Player->setPosition(this->Player->getGlobalBounds().left, this->window->getSize().y - this->Player->getGlobalBounds().height);
	}
}

void game::initText()
{
    this->Text = new text();
}
void game::render()
{
	/**
		@return void

		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/
	this->window->clear();
    this->window->draw(background);
    this->renderPlayer();
    this->renderEnemy();
    this->renderText();
    this->Text->SetPositionEH(this->Enemy->getPosition().x-100,this->Enemy->getPosition().y-20); //chosen relativly to current sprites
    this->Text->SetPositionPH(this->Player->getPosition().x+30,this->Player->getPosition().y-30); //chosen relativly to current sprites
	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	this->window->display();
}
void game::renderText()
{
    this->Text->render(*this->window);
}
void game::resume()
{
    	while (this->window->pollEvent(this->ev))
	{
        if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape){
            if(this->pause==true)
            {
            this->pause=false;
            }
            if(this->pause==false)
            {
            this->pause = true;
            }
		}
	}
}
void game::update()
{
    sf::Clock clock;
    float deltaTime ;
	//Polling window events
	while (this->window->pollEvent(this->ev))
	{

		if (this->ev.type == sf::Event::Closed)
			this->window->close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape){
            if(this->pause==true)
            {
            this->pause=false;
            }
            if(this->pause==false)
            {
            this->pause = true;
            }
		}

		if (
			this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			)
		{
			this->Player->resetAnimationTimer();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"],
			this->Player->getPosition().x + this->Player->getGlobalBounds().width/2.f,
			this->Player->getPosition().y,
			0.f,
			-1.f,
			5.f
			)
		);
        }

        clock.restart();

	}
    deltaTime = clock.restart().asSeconds();
    this->updateEnemy(deltaTime);

    this->Text->update(this->Enemy->health,this->Player->health);

    this->updatePlayer();

	this->updateCollision();

	this->updateBullets();


}

game::game()
{
    this->windowCreate();
    this->initPlayer();
    this->initbackground();
    this->initEnemy();
    this->initText();
    this->initTextures();
}
game::~game()
{
	delete this->window;
    delete this->Player;
    delete this->Enemy;
    delete this->Text;
    for (auto &i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}
}

