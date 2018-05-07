#include <iostream>
#include <string>
#include <stdio.h>
#include "Cell.hpp"

using namespace std;

	char Cell::get(){
		return this->value;
	}
	void Cell::set(char c){
		if(c=='X'||c=='O') this->value=c;
	}
	Cell& Cell::operator= (char c){
		this->set(c);
		return *this;
	}
			