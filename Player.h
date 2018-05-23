#include "Coordinate.h"
#include "Board.h"
using namespace std;
#pragma once

class Player{
	private:
		char myChar='X';
	public:	
		virtual const string name() const{return "";}
		virtual const Coordinate play(const Board& board){return {0,0};}
		
		char getChar(){
			return myChar;
			}

		void setChar(char c){
			myChar=c;
			}
};
