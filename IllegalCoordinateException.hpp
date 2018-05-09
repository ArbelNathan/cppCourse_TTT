#ifndef tic_tac_toe
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
using namespace std;
#pragma once

class IllegalCoordinateException{
	private:
		int corX, corY;
	public:
		IllegalCoordinateException(int x, int y);
		string theCoordinate() const;
}; 

#endif