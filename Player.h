using namespace std;
#pragma once

class Player{
	public:
		Player(){}
		virtual const string name();
		virtual const Coordinate play(const Board& board);
		~Player();
};
	
