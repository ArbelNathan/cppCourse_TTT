#include <stdio.h>
#include <string>
#include "DummyPlayers.h"
using namespace std;
#pragma once


class Champion: public Player{
	private:
		string rival;
		bool meFirst;
	public:
		const string name() const override { return "Inna and Arbel"; }
		const Coordinate play(const Board& board) override;
		
		private void getRival(string name, bool first);
};
