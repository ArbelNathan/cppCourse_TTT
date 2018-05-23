using namespace std;
#include "Coordinate.h"
#include "Board.h"
#pragma once

class Player{
	public:
	char myChar;
	
		Player(){
			myChar='X';
		}
		
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
		
	char getChar(){
		return myChar;
		}
	
        void setChar(char c){
		myChar=c;
		}
};
