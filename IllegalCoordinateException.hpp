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
		IllegalCoordinateException(){}
		void setCoor(int x, int y){ this->corX = x; this->corY = y;}
		string theCoordinate() const{ 
			return to_string(corX) + "," + to_string(corY);
		}
}; 
