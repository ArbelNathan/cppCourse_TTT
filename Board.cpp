#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;
#include "Board.h"
	
	Board::Board(){size=0;}
    Board::Board(int a){
        size=a;
        gameTable = new Cell*[size];
        for(int i = 0; i < size; ++i) {
           gameTable[i] = new Cell[size];
        }
    }
    Board::Board(const Board& b){
        size=b.size;
        gameTable = new Cell*[size];
        for(int i = 0; i < size; ++i) {
            gameTable[i] = new Cell[size];
        }
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                (*this)[{i,j}]=b.gameTable[i][j];
            }
        }
    }
	
	
	
		//Board[{}] return Cell
	Cell& Board::operator[] (list<int> l){
			int x=l.front();
			int y=l.back();
			if(x > this->size-1 || y > this->size-1){
				throw IllegalCoordinateException(x,y);
			}
			return this->gameTable[x][y];
		}
        
        ostream& operator<< (ostream& os, const Board& n){
        	for (int i = 0; i < n.size; i++) {
        		for (int j = 0; j < n.size; j++) {
        			os<<n.gameTable[i][j].get();
        			
        		} 
        	os<<endl;
        	}
        	return os;
        }
        
        //Board='.'
    	Board& Board::operator= (char a){
    		 if(a=='.'){
			for(int i = 0; i < this->size; i++)
			    for(int j = 0; j < this->size; j++)
				    this->gameTable[i][j]=a ;
    		 }
		else if(a != 'X' && a != 'O'){
			throw IllegalCharException(a);
		}
		return *this;
    	}
    	
    	//Board=Board
    	Board& Board::operator= (const Board& b){
    			if(this->size!=b.size){
    			    this->resize(b.size);
    			}
    	        for (int i = 0; i < this->size; i++) {
                    for (int j = 0; j < this->size; j++) {
    			        (*this)[{i,j}]=b.gameTable[i][j];
        	        }
                }
    			
    			return *this;
    		
    	}

    void Board::resize(int size){
        this->size=size;
        this->gameTable = new Cell*[size];
            for(int i = 0; i < size; ++i) {
               this->gameTable[i] = new Cell[size];
               
            }
    }
    
    void Board::setSize(int size){this->size = size;}
    int Board::getSize(){return this->size;}
    void Board::setGameTable(Cell** g){*this->gameTable = *g;}
    Cell** Board::getGameTable(){return this->gameTable;}

	//destructor
	Board::~Board(){
	    for (int i = 0; i < this->size; i++){
            delete [] gameTable[i];
        }
    
        delete [] gameTable;
	

	}
   


