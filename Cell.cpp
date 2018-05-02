#include <iostream>
#include <string>
#include <stdio.h>
#include "Cell.hpp"

using namespace std;


 	ostream& operator<< (ostream& os, const Cell& n){
		for(int i = 0;i<n.size ;i++){
		cout<< n.size<< endl;
			n.cell[i] = '.';
			os<<n.cell[i];
		    os<<"\n";
		}
		return os;
	}

	Cell& Cell::operator= (char a){
		if(a == '.' ){
			for(int i = 0;i<this->size ;i++){
				cell[i] = '.';
			}
		}
		return *this;
	}
