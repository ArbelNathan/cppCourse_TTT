#include <stdio.h>
#include "Board.h"
#include "DummyPlayers.h"
#include "Player.h"
using namespace std;
#pragma once

class TicTacToe{
	private:
		int sizeBoard;
		Board* game = new Board();
	public:
		TicTacToe(){sizeBoard = 0;}
		TicTacToe(int size){sizeBoard = size; game = new Board(size);}
		void play(const XYPlayer& xPlayer,const YXPlayer& oPlayer);	
		const Board& board(const Board& b);
		Player& winner();

};
