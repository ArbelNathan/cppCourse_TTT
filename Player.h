using namespace std;
#pragma once
using Coordinate = Cell;

class Player{
	public:
		Player(){}
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
		~Player();
};
	
