#include <stdio.h>
#include <string>
#include <string.h>
#include "DummyPlayers.h"
#include "Coordinate.h"
using namespace std;
#pragma once


class Champion: public Player{
	private:
		string rival;
		bool meFirst;
	
	public:
		const string name() const  { return "Inna , Arbel and Anna"; }
		const Coordinate play(const Board& board) ;
		void getRival(string name, bool first);
};
