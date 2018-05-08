#include <iostream>
#include <string>
#include <stdio.h>
#include <exception>
#include <exception>
#include <stdbool.h>
using namespace std;
#pragma once

class IllegalCharException: public exception{
	private:
	 	char c;
	public:
		IllegalCharException(){}
		void setChar(char a){ c = a;}		
		char theChar() const{ 
			return c;
		}
}; 
