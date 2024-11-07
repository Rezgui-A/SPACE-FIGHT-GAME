#pragma once

class text
{
private:



    //initialisation
    void eHinitfont();
    void EhinitText();
    sf::Font font;



public:
    text();
    virtual~text();
    //texts
    sf::Text playerHealth;
    sf::Text enemyHealth;
    //functions
    void SetPositionPH(float getPosX, float getPosY); // ENEMY HEALTH HP POSITION
    void SetPositionEH(float getPosX,float getPosY); // PLAYER HEALTH HP POSITIONN
    void render(sf::RenderTarget & target);
    void update(int EHEALTH,int PHEALTH);
};
