#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
	if(rival=="XYPlayer"){
		if(meFirst){
			YXPlayer player;
			return player.play(board);
		}
		else{
			int y=1;
			for (int x=0; x<board.size(); ++x) {
				Coordinate c{x,y};
				if (board[{c.getRow(), c.getCol()}]=='.') {
					return c;
				}
			}
		}
	}
	if(rival=="YXPlayer"){
		if(meFirst){
			XYPlayer player;
			return player.play(board);
		}
		else{
			int x=1;
			for (int y=0; x<board.size(); ++x) {
				Coordinate c{x,y};
				if (board[{c.getRow(), c.getCol()}]=='.') {
					return c;
				}
			}
		}
	}

	else 
	{ 	
		XYPlayer player;
		return player.play(board);	
	}
}

void Champion::getRival(string name, bool first){
	this->rival=name;
	this->meFirst=first;
}
