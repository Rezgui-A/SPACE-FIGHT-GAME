#include "includes.hpp"
#include "text.hpp"
#include <string>
void text::eHinitfont()
{

    if (!this->font.loadFromFile("fonts/PixellettersFull.ttf"))
    {
        std::cout<<"Error could not load font from fonts/PixellettersFull.ttf"<<"\n";
    }

}
void text::EhinitText()
{
    // set the string to display
    this->playerHealth.setFont(this->font);
    this->enemyHealth.setFont(this->font);
}
void text::SetPositionEH(float getPosX,float getPosY)
{
    this->enemyHealth.setPosition(getPosX,getPosY);
}
void text::SetPositionPH(float getPosX,float getPosY)
{
    this->playerHealth.setPosition(getPosX,getPosY);
}
void text::render(sf::RenderTarget & target)
{
    target.draw(this->playerHealth);
 	target.draw(this->enemyHealth);
}
void text::update(int EHEALTH,int PHEALTH)
{
    this->playerHealth.setString(std::to_string(PHEALTH)+"HP");
    this->enemyHealth.setString(std::to_string(EHEALTH) + "HP");
}
text::text()
{
   this->eHinitfont();
   this->EhinitText();
}
text::~text()
{

}

