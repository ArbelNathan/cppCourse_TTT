
#include "Board.h"
	
	Board::Board(){Size=0;}
     Board::Board(int a){
        Size=a;
        gameTable = new Cell*[Size];
        for(int i = 0; i < Size; ++i) {
           gameTable[i] = new Cell[Size];
        }
    }

    Board::Board(const Board& b){
        Size=b.Size;
        gameTable = new Cell*[Size];
        for(int i = 0; i < Size; ++i) {
            gameTable[i] = new Cell[Size];
        }
        for (int i = 0; i < this->Size; i++) {
            for (int j = 0; j < this->Size; j++) {
                (*this)[{i,j}]=b.gameTable[i][j];
            }
        }
    }
	
		//Board[{}] return Cell
	Cell& Board::operator[] (list<int> l){
		int x=l.front();
		int y=l.back();
		if(x > this->Size-1 || y > this->Size-1){
			throw IllegalCoordinateException(x,y);
		}
		return this->gameTable[x][y];
	}
		Cell& Board::operator[] (Coordinate& c) const{
	    int x=c.getRow();
		int y=c.getCol();
		if(x > this->Size-1 || y > this->Size-1){
			throw IllegalCoordinateException(x,y);
		}
		return this->gameTable[x][y];
	}
        
        ostream& operator<< (ostream& os, const Board& n){
        	for (int i = 0; i < n.Size; i++) {
        		for (int j = 0; j < n.Size; j++) {
        			os<<n.gameTable[i][j].get();
        		} 
        	os<<endl;
        	}
        	return os;
        }
        
        //Board='.'
    	Board& Board::operator= (char a){
    		 if(a=='.'){
			for(int i = 0; i < this->Size; i++)
			    for(int j = 0; j < this->Size; j++)
				    this->gameTable[i][j]=a ;
    		 }
		else if(a != 'X' && a != 'O'){
			throw IllegalCharException(a);
		}
		return *this;
    	}
    	
    	//Board=Board
    	Board& Board::operator= (const Board& b){
    			if(this->Size!=b.Size){
    			    this->resize(b.Size);
    			}
    	        for (int i = 0; i < this->Size; i++) {
                    for (int j = 0; j < this->Size; j++) {
    			        (*this)[{i,j}]=b.gameTable[i][j];
        	        }
                }
    			
    			return *this;
    		
    	}

    void Board::resize(int Size){
        this->Size=Size;
        this->gameTable = new Cell*[Size];
            for(int i = 0; i < Size; ++i) {
               this->gameTable[i] = new Cell[Size];
               
            }
    }
    
    void Board::setSize(int Size){this->Size = Size;}
    int Board::size() const {return this->Size;}
    void Board::setGameTable(Cell** g){*this->gameTable = *g;}
    Cell** Board::getGameTable(){return this->gameTable;}

	//destructor
	Board::~Board(){
	    for (int i = 0; i < this->Size; i++){
            delete [] gameTable[i];
        }
    
        delete [] gameTable;
	

	}
	

   


