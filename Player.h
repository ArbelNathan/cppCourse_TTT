using namespace std;
#include "Coordinate.h"
#pragma once

class Player{
	public:
		Player(){}
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
};
	
