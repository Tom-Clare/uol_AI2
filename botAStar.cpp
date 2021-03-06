//======================================================================================
//Source code for a bot that simply moves directly towards the player
//
//(c) Thomas Clare, University of Lincoln, School of Computer Science, 2021
//======================================================================================

#include "bots.h"
#include "stdlib.h"

void cBotAStar::ChooseNextGridPosition()
{
	//======================================================================================
	// We use gLevel to access environment layout
	// And gTarget to get target position
	// This function is called when a bot arrives at its current target location, to set the 
	// next grid position to reach the final target  
	//======================================================================================

	if (cAStar::pathPerhaps.empty()) {
		return;
	}

	bool done = false;
	//Use while loop, as new selected location might not be valid
	while (!done) {

		int x = cAStar::pathPerhaps[cAStar::pathIndex].first;
		int y = cAStar::pathPerhaps[cAStar::pathIndex].second;

		done = SetNext(x, y, gLevel);

	}

	cAStar::pathIndex = cAStar::pathIndex - 1;
}