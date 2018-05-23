using namespace std;
#include "Coordinate.h"
#include "Board.h"
#pragma once

class Player{
	public:
	char sign;
	
		Player(){
			sign='X';
		}
		
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
		
	char getChar(){
		return sign;
		}
	
        void setChar(char c){
		sign=c;
		}
};
