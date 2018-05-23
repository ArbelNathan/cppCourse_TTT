#include <stdio.h>
#include <iostream>
#include "TicTacToe.h"
using namespace std;


Board TicTacToe::board() const 
{
    return game;
}

Player& TicTacToe::winner() const
{
   // game = '.';
    return *Winner;
}

	
	void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    size_t count = 0;
    size_t TableSize = sizeBoard * sizeBoard;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    while (count < TableSize)
    {
        if (turn('X', xPlayer, oPlayer))  // X won.
            return;
        count++;
        if (turn('O', xPlayer, oPlayer) && count < TableSize)  // O won.
            return;
        count++;
    }
    //draw case.
    Winner = &oPlayer;  
}
	
	
	bool TicTacToe::turn(char player, Player& xPlayer, Player& oPlayer) {
    try
        {
            Coordinate c;
            player == 'X' ? c = xPlayer.play(board()) : c = oPlayer.play(board());
            if (game[c] != '.')
                throw std::string("Illegal Player");
            game[c] = player;
            if (GameWinned(board(), c, player))
            {
                player == 'X' ? Winner = &xPlayer : Winner = &oPlayer;
                return true;
            }
            return false;
        }
    catch (...)  // All the exception are caught.
        {
            player == 'X' ? Winner = &oPlayer : Winner = &xPlayer;
            return true;
        }
}
	
	
	 bool TicTacToe::GameWinned(Board board, Coordinate c, char player) {
     Count up = {1, true};
     Count down = {0, true};
	 Count right = {1, true};
	 Count left = {0, true};
	 Count diagonalLeftDown = {1, true};
	 Count diagonalLeftUp = {1, true};
	 Count diagonalRightDown = {0, true};
	 Count diagonalRightUp = {0, true};
	 for (int i = 1; i < board.size(); i++) {
        if (isPlayer({c.getRow(), c.getCol() + i}, player) && up.flag)
            up.sum++;
        else
            up.flag = false;
        if (isPlayer({c.getRow(), c.getCol() - i}, player) && down.flag)
            down.sum++;
        else
            down.flag = false;
		if (isPlayer({c.getRow() + i, c.getCol()}, player) && right.flag)
            right.sum++;
		else
            right.flag = false;
		if (isPlayer({c.getRow() - i, c.getCol()}, player) && left.flag)
            left.sum++;
		else
            left.flag = false;
		if (isPlayer({c.getRow() - i, c.getCol() - i}, player) && diagonalLeftDown.flag)
            diagonalLeftDown.sum++;
		else
            diagonalLeftDown.flag = false;
		if (isPlayer({c.getRow() - i, c.getCol() + i}, player) && diagonalLeftUp.flag)
            diagonalLeftUp.sum++;
		else
            diagonalLeftUp.flag = false;
		if (isPlayer({c.getRow() + i, c.getCol() - i}, player) && diagonalRightDown.flag)
            diagonalRightDown.sum++;
		else
            diagonalRightDown.flag = false;
		if (isPlayer({c.getRow() + i, c.getCol() + i}, player) && diagonalRightUp.flag)
            diagonalRightUp.sum++;
		else
            diagonalRightUp.flag = false;
	}
	int sumHigh = up.sum + down.sum;
	int sumSide = right.sum + left.sum;
	int sumFirstDiagonal = diagonalLeftDown.sum + diagonalRightUp.sum;
	int sumSecondDiagonal = diagonalLeftUp.sum + diagonalRightDown.sum;
     if (sumHigh  == board.size() || sumSide == board.size() || sumFirstDiagonal == board.size() || sumSecondDiagonal == board.size()) {
         return true;
     }
    return false;
}

void TicTacToe::Rival(Player& xPlayer, Player& oPlayer){
    if (xPlayer.name()=="Inna , Arbel and Anna"){
       ((Champion) xPlayer).getRival(oPlayer.name(), false);
        
    }
    else if (oPlayer.name()=="Inna , Arbel and Anna"){
        (Champion) xPlayer).getRival(xPlayer.name(), false);
    }
    
}	
	
	
	
bool TicTacToe::isPlayer(Coordinate c, char player) {
    if (c.getRow() < 0 || c.getRow() >= sizeBoard || c.getCol()< 0 || c.getCol() >= sizeBoard)
        return false;
    char cell = game[c].get();
	if (player == cell)
		return true;
	return false;
}
