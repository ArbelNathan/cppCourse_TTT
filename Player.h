using namespace std;
#pragma once
#include "Coordinate.h"

class Player{
	public:
		Player(){}
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
		~Player();
};
	
