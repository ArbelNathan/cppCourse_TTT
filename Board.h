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
    
        Board();
        Board(int a);
        Board(const Board& b);
        
        
        Cell& operator[] (list<int> l);//Board[{}] return Cell
        
        friend ostream& operator<< (ostream& os, const Board& n);
        
    	Board& operator= (char a);//Board='.'
    	Board& operator= (const Board& b);//Board=Board
        void setSize(int size);
        int getSize();
        void setGameTable(Cell** g);
        Cell** getGameTable();
        void resize(int size);
    	~Board();//destructor
        
   
};

#endif
