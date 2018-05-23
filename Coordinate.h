#include <stdio.h>
#pragma once
using namespace std;

class Coordinate{
	private:
		uint row,col;
	public:
		Coordinate(){row=0; col=0;}
        	Coordinate(uint a, uint b){ row = a; col = b; }
		uint getRow(){return row;}
		uint getCol(){return col;}

};
