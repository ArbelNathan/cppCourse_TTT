#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#include "Board.hpp"


    char& operator[] (const char a[]) {
        //need to check!!
          return gameTable[a[0]][a[1]];
    }

    ostream& operator<< (ostream& os, const Board& n){
        for(int i = 0;i<n.size ;i++){
            for(int j = 0; j<n.size; j++)
            {
        
                	n.gameTable[i][j] = '.';
                os<<n.gameTable[i][j];
                ;
            }
            os<<"\n";
        }
        return os;
     }