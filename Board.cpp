#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;
#include "Board.h"

		//Board[{}] return Cell
	Cell& Board::operator[] (list<int> l){
			if(l.front() > this->size-1 || l.back() > this->size-1){
				IllegalCoordinateException exCoor;
				exCoor.setCoor(l.front(),l.back());
				throw exCoor;
			}
			return this->gameTable[l.front()][l.back()];
		}
        
        ostream& operator<< (ostream& os, const Board& n){
        	for (int i = 0; i < n.size; i++) {
        		for (int j = 0; j < n.size; j++) {
        			os<<n.gameTable[i][j].get();
        			
        		} 
        	os<<"\n";
        	}
        	return os;
        }
        
        //Board='.'
    	Board& Board::operator= (char a){
    		 if(a=='.'){
    			Board temp{this->size};
    			this->setSize(temp.getSize());
			for(int i = 0; i < this->size; i++)
				this->gameTable[i] = temp.gameTable[i];
    			//this->setGameTable(temp.getGameTable());
    		 }
		else if(a != 'X' && a != 'O'){
			IllegalCharException exChar;
			exChar.setChar(a);
			throw exChar;
		}
		return *this;
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
    			this->setSize(temp.getSize());
    			this->setGameTable(temp.getGameTable());
    			return *this;
    		
    	}

	//destructor
	Board::~Board(){
		delete [] gameTable;

	}
   


