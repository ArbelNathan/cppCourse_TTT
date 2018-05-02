#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;
#include "Board.hpp"
#include "Cell.hpp"

	
	/*char& Board::operator[] ( list<int> l) {
		cout<< l.front() << " " <<  l.back() << endl;
		return this->gameTable[l.front()][l.back()] ;
	}

	*/

	ostream& operator<< (ostream& os, const Board& n){
		for(int i = 0;i<n.size ;i++){
		
		  for(int j = 0; j<n.size; j++)
		   {
		        n.gameTable[i][j] = '.';
		    	os<<n.gameTable[i][j];
		   }
		    os<<"\n";
		}
		return os;
	}

	//overload = operator
	Board& Board::operator= (const Board& b){
		this->size = b.size;
		this->gameTable = b.gameTable;
		return *this;
	}
	
/*	//overload = int
	Board& Board::operator= (char a){
		if(a == '.' ){
			for(int i = 0;i<this->size ;i++){
			    for(int j = 0; j<this->size; j++)
			    {
				gameTable[i][j] = '.';
			    }
			//gameTable[i][j] = "/n";
			}
		}
		return *this;
	}*/

	/*//overload = int
	Board& Board::operator= (const Board& b, int start, int end, char a){
		b[start][end] = a;
		return b;
	}*/



