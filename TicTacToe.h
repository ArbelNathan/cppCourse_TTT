#include <stdio.h>
#include "Board.h"
#include "DummyPlayers.h"
#include "Player.h"
using namespace std;
#pragma once

class TicTacToe{
	private:
		int sizeBoard;
		Board game;
        Player* Winner;
        
        
	public:
	//constructors
		TicTacToe(){
			sizeBoard = 0;
		}
	
        TicTacToe(int size)
        {
        	sizeBoard = size; 
        	game = new Board{size};
        }
        
        
		Board board();
		void play(Player& xPlayer, Player& oPlayer);
		bool turn(char player, Player& xPlayer, Player& oPlayer);
		bool GameWinned(Board board, Coordinate c, char player);
		bool isPlayer(Coordinate c, char player);

};



 struct Count{
	int sum;
	bool flag;
};
