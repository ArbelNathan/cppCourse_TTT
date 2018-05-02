#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#pragma once

class Cell{
	private:
		char* cell = new char[0];
		int size;
	public:
		Cell(){}
		Cell(int a){
		    size=a;
		    cell = new char[a];
		}
		char* get(){ return cell;}
		char set(int n){ cell = new char[n];  size=n;}
		//overload = int
		Cell& operator= (char a);
		friend ostream& operator<< (ostream& os, const Cell& n);
			


};
