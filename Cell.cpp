#include <iostream>
#include <string>
#include <stdio.h>
#include "Cell.h"
using namespace std;

	char Cell::get()const{
		return this->value;
	}
	void Cell::set(char c){
		if(c != 'X' && c != 'O'&& c != '.'){
			throw 	IllegalCharException(c);
		}
		else { this->value=c;}
	}
	Cell& Cell::operator= (char c){
		this->set(c);
		return *this;
	}
	Cell& Cell::operator= (const Cell& c){
	this->value=c.value;		
	}
			
