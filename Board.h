#ifndef tic_tac_toe
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <list>
#include "Cell.h"
#include "IllegalCharException.hpp"
#include "IllegalCoordinateException.hpp"
#include "Coordinate.h"
#include <fstream>
using namespace std;
#pragma once

class Board{
    private:
        Cell** gameTable=new Cell*[0];
        int Size=0;
    
    public:
    
        Board();
        Board(int a);
        Board(const Board& b);
        
        
        Cell& operator[] (list<int> l) const ;//Board[{}] return Cell
       Cell& operator[] (Coordinate& c) const;//Board[{}] return Cell
        friend ostream& operator<< (ostream& os, const Board& n);
        friend istream& operator>> (istream& is, Board& n);
        
    	Board& operator= (char a);//Board='.'
    	Board& operator= (const Board& b);//Board=Board
        void setSize(int Size);
        int size() const;
        void setGameTable(Cell** g);
        Cell** getGameTable();
        void resize(int Size);
	string draw(int n); //converts txt drawing to image
    	~Board();//destructor
        
   
};

	
struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

#endif

