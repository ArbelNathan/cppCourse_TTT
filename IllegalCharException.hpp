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
		IllegalCharException(char a){c = a}
		
		char theChar() const{ 
			return c;
		}
}; 
