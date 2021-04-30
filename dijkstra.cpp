#include "bots.h"

class cDijkstra {
public: 
	bool closed[GRIDWIDTH][GRIDHEIGHT]; //is location closed?
	float cost[GRIDWIDTH][GRIDHEIGHT]; //cost of moving to that location
	int linkX[GRIDWIDTH][GRIDHEIGHT]; //???
	int linkY[GRIDWIDTH][GRIDHEIGHT]; //???
	bool inPath[GRIDWIDTH][GRIDHEIGHT]; // if location is in final path


};