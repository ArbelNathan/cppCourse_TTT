#include <stdio.h>
#include "Board.h"
using namespace std;
#pragma once

class TicTacToe{
	private:
		int sizeBoard;
	public:
		TicTacToe(){sizeBoard = 0;}
		void play(xPlayer, oPlayer);	
		Board& board();
		winner();

};
