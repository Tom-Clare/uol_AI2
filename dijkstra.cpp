#include "bots.h"

void cDijkstra::Build(cBotBase &bot) {
	
	// set all nodes to open
	for (bool status : closed)
		status = false;

	// set all costs to a very high number
	for (int w = 0; w < GRIDWIDTH; w++) {
		for (int h = 0; h < GRIDHEIGHT; h++) {
			cost[w][h] = 1000000.0f;
		}
	}

	// linkX and linkY aren't important, so just set to -1 for now
	for (int* coordX : linkX)
		*coordX = -1;
	for (int* coordY : linkY)
		*coordY = -1;

	// also, we do not yet know the path, so init all values to false
	for (bool* val : inPath)
		*val = false;

	// Begin th esearch!!
	
	// set cost of bot's current position to zero
	cost[bot.PositionX()][bot.PositionY()] = 0;

	while (!closed[gTarget.PositionX()][gTarget.PositionY()]) {

		float min = costDefault; // init min element value
		int minX = 0; // init min values X position
		int minY = 0; // init min values Y position

		for (int x = 0; x < GRIDWIDTH; x++) {
			for (int y = 0; y < GRIDHEIGHT; y++) {
				if (cost[x][y] < min && // less than current min
					!closed[x][y] && // not closed
					gLevel.isValid(x,y)) { // not blocked

					min = cost[x][y]; // update min value
					minX = x;
					minY = y;
				}
			}
		}

		closed[minX][minY] = true; // close position with lowest cost

		this->CalculateNeighbours(minX, minY);

		

	}
	
	bool done = false; //set to true when we are back at the bot position
	int nextClosedX = gTarget.PositionX(); //start of path
	int nextClosedY = gTarget.PositionY(); //start of path
	while (!done)
	{
		inPath[nextClosedX][nextClosedY] = true;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		nextClosedX = linkX[tmpX][tmpY];
		nextClosedY = linkY[tmpX][tmpY];
		if ((nextClosedX == bot.PositionX()) && (nextClosedY ==
			bot.PositionY())) done = true;
	}

	completed = true;
}

void cDijkstra::CalculateNeighbours(int x, int y) {
	// This function will update the cost of all neighbours of a specified node
	int tempX;
	int tempY;
	float parentCost = cost[x][y]; // This is the value that (we assume) has just been closed

	// generate list of neighbours and costs
	// Direction: TL, T, TR, L, R, BL, B, BR
	int neighbourNodesX[] = {x-1, x, x+1, x-1, x+1, x-1, x, x+1}; 
	int neighbourNodesY[] = {y-1, y-1, y-1, y, y, y+1, y+1, y+1};
	float neighbourNodesCost[] = { 1.4, 1, 1.4, 1, 1, 1.4, 1, 1.4 };
	for (int nodeIndex = 0; nodeIndex < sizeof(neighbourNodesX)/sizeof(neighbourNodesX[0]); nodeIndex++) {

		tempX = neighbourNodesX[nodeIndex];
		tempY = neighbourNodesY[nodeIndex];
		//perform checks first
		if (closed[neighbourNodesX[nodeIndex]][neighbourNodesY[nodeIndex]] 
			|| !gLevel.isValid(neighbourNodesX[nodeIndex],neighbourNodesY[nodeIndex])) {
			continue; // skip over this value if closed or not a valid node
		}

		float newCost = neighbourNodesCost[nodeIndex] + parentCost; //cost of parent, plus the direction cost

		// if the new cost is less than the cost we have already saved, save that cost!
		if (cost[tempX][tempY] == costDefault
			|| newCost < cost[tempX][tempY]) {
			cost[tempX][tempY] = newCost;
			linkX[tempX][tempY] = x;
			linkY[tempX][tempY] = y;
		}
	}
}

cDijkstra gDijkstra;