#ifndef tic_tac_toe
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
		char get() const;
		void set(char c);
		Cell& operator= (char c);
		Cell& operator= (const Cell& c);
		bool operator ==(char c) const {if(value==c)return true; return false;}
		bool operator ==(const Cell& c) const {if(this->value==c.get())return true; return false;}
};

#endif