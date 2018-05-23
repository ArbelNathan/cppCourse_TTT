#include "Coordinate.h"
#include "Board.h"
using namespace std;
#pragma once

class Player{
	private:
		char myChar='X';
	public:
		//Player();	
		virtual const string name() const;
		virtual const Coordinate play(const Board& board);
		
		char getChar(){
			return myChar;
			}

		void setChar(char c){
			myChar=c;
			}
};
