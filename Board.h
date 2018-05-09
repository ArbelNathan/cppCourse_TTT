#ifndef tic_tac_toe
#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include "Cell.h"
#include "IllegalCharException.hpp"
#include "IllegalCoordinateException.hpp"
using namespace std;
#pragma once

class Board{
    private:
        Cell** gameTable=new Cell*[0];
        int size=0;
    
    public:
    
        Board(){size=0;}
        Board(int a){
            size=a;
            gameTable = new Cell*[size];
            for(int i = 0; i < size; ++i) {
               gameTable[i] = new Cell[size];
            }
        }
        Board(const Board& b){
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
        
        
        Cell& operator[] (list<int> l);//Board[{}] return Cell
        
        friend ostream& operator<< (ostream& os, const Board& n);
        
    	Board& operator= (char a);//Board='.'
    	Board& operator= (const Board& b);//Board=Board
	void setSize(int size){this->size = size;}
	int getSize(){return this->size;}
	void setGameTable(Cell** g){*this->gameTable = *g;  }
	Cell** getGameTable(){return this->gameTable;}
    void resize(int size);
    	~Board();//destructor
        
   
};

#endif
