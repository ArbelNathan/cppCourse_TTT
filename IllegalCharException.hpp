#ifndef tic_tac_toe
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
using namespace std;
#pragma once

class IllegalCharException{
	private:
	 	char c;
	public:
		IllegalCharException(char a);
		char theChar() const;
}; 

#endif