#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#pragma once


class Board{
    private:
        char** gameTable=new char*[0];
        int size;
    
    public:
        Board(){}
        Board(int a){
            size=a;
            gameTable = new char*[a];
            for(int i = 0; i < a; ++i) {
               gameTable[i] = new char[a];
            }
        }
        
        char& operator[] (const char a[]) {
          return gameTable[a[0]][a[1]];
      }
        friend ostream& operator<< (ostream& os, const Board& n);
        
    
};