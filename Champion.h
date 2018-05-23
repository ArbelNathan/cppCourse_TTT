#include <stdio.h>
#include <string>
#include "DummyPlayers.h"
#include "Coordinate.h"
using namespace std;
#pragma once


class Champion: virtual public Player{
	private:
		string rival;
		bool meFirst;
	
	public:
		const string name() const override { return "Inna , Arbel and Anna"; }
		const Coordinate play(const Board& board) override;
		void getRival(string name, bool first);
};
