#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;
#include "Board.hpp"
#include "Cell.hpp"

		//Board[{}] return Cell
		Cell& Board::operator[] (list<int> l){
			return this->gameTable[l.front()][l.back()];
		}
        
        ostream& operator<< (ostream& os, const Board& n){
        	for (int i = 0; i < n.size; i++) {
        		for (int j = 0; j < n.size; j++) {
        			os<<n.gameTable[i][j].get();
        			os<<' ';
        		} 
        	os<<"\n";
        	}
        	return os;
        }
        
        //Board='.'
    	Board& Board::operator= (char a){
    		 if(a=='.'){
    			Board temp{this->size};
    			*this=temp;
    		 }
    	}
    	
    	//Board=Board
    	Board& Board::operator= (const Board& b){
    			Board temp{this->size};
    			for (int i = 0; i < this->size; i++) {
        			for (int j = 0; j < this->size; j++) {
        				if(b.gameTable[i][j].get()!='.')
    						temp[{i,j}]=b.gameTable[i][j].get();
        			}
    			}
    			this->gameTable=temp.gameTable;
    			return *this;
    		
    	}
   

