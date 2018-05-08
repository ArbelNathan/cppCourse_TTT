#include <iostream>
#include <string>
#include <stdio.h>
#include "Cell.h"
using namespace std;

	char Cell::get(){
		return this->value;
	}
	void Cell::set(char c){
		if(c != 'X' && c != 'O'){
			IllegalCharException exChar;
			exChar.setChar(c);
			throw exChar;
		}
		else { this->value=c;}
	}
	Cell& Cell::operator= (char c){
		this->set(c);
		return *this;
	}
			
