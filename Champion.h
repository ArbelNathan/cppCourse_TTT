#include <stdio.h>
#include <string>
using namespace std;
#pragma once


class Champion: public Player{
	public:
		const string name() const override { return "Inna and Arbel"; }
		const Coordinate play(const Board& board) override;
		private const Coordinate xyplayer(const Board& board); 
		private const Coordinate yxplayer(const Board& board);
		private const Coordinate IllegalPlayer(const Board& board);
		private const Coordinate ExceptionPlayer(const Board& board);
};
