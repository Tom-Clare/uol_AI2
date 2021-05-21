#pragma once
//======================================================================================
//Header file for bots: initially cBotRandom is defined here, but other bot classes
//can go here too
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "botbase.h"

class cBotRandom : public cBotBase
{
	virtual void ChooseNextGridPosition();
};

class cBotSimple : public cBotBase
{
	virtual void ChooseNextGridPosition();
};

class cDijkstra
{
	public:
		bool closed[GRIDWIDTH][GRIDHEIGHT]; //is location closed?
		float cost[GRIDWIDTH][GRIDHEIGHT]; //cost of moving to that location
		int linkX[GRIDWIDTH][GRIDHEIGHT]; // Holds X value of which neighbor the fastest route came through
		int linkY[GRIDWIDTH][GRIDHEIGHT]; // Holds Y value of which neighbor the fastest route came through
		bool inPath[GRIDWIDTH][GRIDHEIGHT]; // if location is in final path

		bool completed;

		cDijkstra() { completed = false; }

		virtual void Build(cBotBase& bot);
};

