//======================================================================================
//Source code for a bot that simply moves directly towards the player
//
//(c) Thomas Clare, University of Lincoln, School of Computer Science, 2021
//======================================================================================

#include "bots.h"
#include "stdlib.h"

void cBotSimple::ChooseNextGridPosition()
{
	//======================================================================================
	// We use gLevel to access environment layout
	// And gTarget to get target position
	// This function is called when a bot arrives at its current target location, to set the 
	// next grid position to reach the final target  
	//======================================================================================

	bool done = false;
	//Use while loop, as new selected location might not be valid
	while (!done) {

		int adaptX = PositionX();
		int adaptY = PositionY();

		if (adaptX > gTarget.PositionX()) {
			adaptX--;
		}
		else if (adaptX < gTarget.PositionX()) {
			adaptX++;
		}

		if (adaptY > gTarget.PositionY()) {
			adaptY--;
		}
		else if (adaptY < gTarget.PositionY()) {
			adaptY++;
		}

		done = SetNext(adaptX, adaptY, gLevel);

	}
}