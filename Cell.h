
#include <iostream>
#include <string>
#include <stdio.h>
//#include "Board.h"
#include "IllegalCharException.hpp"
using namespace std;
#pragma once

class Cell{
	private:
		char value;
	
	public:
		Cell(): value('.'){}
		char get();
		void set(char c);
		Cell& operator= (char c);
		bool operator ==(char c){if(value==c)return true; return false;}

};
