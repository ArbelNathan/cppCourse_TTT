#include <stdio.h>
#include "Board.h"
#pragma once
using namespace std;

class Coordinate{
	private:
		int row,col;
	public:
		Coordinate(){row=0; col=0;}
        	Coordinate(int a, int b){ row = a; col = b; }
		int getRow(){return row;}
		int getCol(){return col;}

};
