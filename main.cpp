#include "includes.hpp"
#include "game.hpp"
int main()
{
    srand(static_cast<unsigned>(time(0)));
    game Game;
    while (Game.GetGameRunning())
	{
		//Update
		Game.update();

		//Render
		Game.render();
}
	//end of app
	return 0;
}
