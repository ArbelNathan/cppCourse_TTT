#include <stdio.h>
#include <string>
using namespace std;
#pragma once


class Champion: public Player{
	public:
		const string name() const override { return "Inna and Arbel"; }
		const Coordinate play(const Board& board) override;
};
