#include "bots.h"

void cDijkstra::Build(cBotBase &bot) {
	
	// set all nodes to open
	for (bool status : closed)
		status = false;

	// set all costs to a very high number
	for (float* price : cost)
		*price = 1000000.0f;

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

	while (true) {

		float min = cost[0][0]; // init min element value
		int minX = -1; // init min values X position
		int minY = -1; // init min values Y position

		for (int x = 0; x < sizeof(cost); x++) {
			for (int y = 0; y < sizeof(cost); y++) {
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
}

void cDijkstra::CalculateNeighbours(int x, int y) {
	// This function will update the cost of all neighbours of a specified node
	int tempX = -1;
	int tempY = -1;
	float* parentCost = cost[x, y];

	// generate list of neighbours and costs
	// Direction: TL, T, TR, L, R, BL, B, BR
	int neighbourNodesX[] = {x-1, x, x+1, x-1, x+1, x-1, x, x+1}; 
	int neighbourNodesY[] = { x - 1, x - 1, x - 1, x, x, x + 1, x + 1, x + 1 };
	float neighbourNodesCost[] = { 1.4, 1, 1.4, 1, 1, 1.4, 1, 1.4 };
	for (int nodeIndex = 0; nodeIndex < sizeof(neighbourNodesX); nodeIndex++) {

		tempX = [neighbourNodesX[nodeIndex]]; // Why can't I do this? :(((( It won't let me pull this value
		tempY = [neighbourNodesY[nodeIndex]];
		//perform checks first
		if (closed[neighbourNodesX[nodeIndex]][neighbourNodesY[nodeIndex]] 
			|| !gLevel.isValid([neighbourNodesX[nodeIndex]],[neighbourNodesY[nodeIndex]]) {
			continue; // skip over this value if closed or not a valid node
		}
	}
	


	
}