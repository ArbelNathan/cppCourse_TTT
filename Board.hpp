#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include "Cell.hpp"
using namespace std;
#pragma once


class Board{
    private:
        Cell** gameTable=new Cell*[0];
        int size;
    
    public:
        Board(){}
        Board(int a){
            size=a;
            gameTable = new Cell*[a];
            for(int i = 0; i < a; ++i) {
               gameTable[i] = new Cell[a];
            }
        }
        
        char& operator[] (list<int> l) ;
        friend ostream& operator<< (ostream& os, const Board& n);
	Board& operator= (char a);
	Board& operator= (const Board& b);
	//Board& operator= (const Board& b, int start, int end, char a);
        
   
};

