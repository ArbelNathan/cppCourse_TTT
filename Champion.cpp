#include "Champion.h"




const Coordinate Champion::play(const Board& board) {
	if(strcmp(rival,"XYPlayer")) return xyplayer(board);
	if(strcmp(rival,"YXPlayer")) return yxplayer(board);
	if(strcmp(rival,"IllegalPlayer")) return IllegalPlayer(board);
	else return ExceptionPlayer(board);
}

private void Champion::getRival(string name, bool first){
	this->rival=name;
	this->meFirst=first;
}

private const Coordinate Champion::xyplayer(const Board& board){
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
private const Coordinate Champion::yxplayer(const Board& board){
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
private const Coordinate Champion::IllegalPlayer(const Board& board){
		XYPlayer player;
		return player.play(board);	
}
private const Coordinate Champion::ExceptionPlayer(const Board& board){
		XYPlayer player;
		return player.play(board);
} 