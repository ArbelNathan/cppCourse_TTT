#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
	if(strcmp(rival,"XYPlayer")){
		if(meFirst){
			YXPlayer player;
			return player.play(board);
		}
		else{
			uint y=1;
			for (uint x=0; x<board.size(); ++x) {
				Coordinate c{x,y};
				if (board[c]=='.') {
					return c;
				}
			}
		}
	}
	if(strcmp(rival,"YXPlayer")){
		if(meFirst){
			XYPlayer player;
			return player.play(board);
		}
		else{
			uint x=1;
			for (uint y=0; x<board.size(); ++x) {
				Coordinate c{x,y};
				if (board[c]=='.') {
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

private void Champion::getRival(string name, bool first){
	this->rival=name;
	this->meFirst=first;
}
