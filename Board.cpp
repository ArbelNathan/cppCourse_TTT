
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
	Cell& Board::operator[] (list<int> l) const {
		int x=l.front();
		int y=l.back();
		if(x > this->Size-1 || y > this->Size-1){
			throw IllegalCoordinateException(x,y);
		}
		return this->gameTable[x][y];
	}
/*
	Cell& Board::operator[] (Coordinate& c) const{
	    	int x=c.getRow();
		int y=c.getCol();
		if(x > this->Size-1 || y > this->Size-1){
			throw IllegalCoordinateException(x,y);
		}
		return this->gameTable[x][y];
	}
  */      
        ostream& operator<< (ostream& os, const Board& n){
        	for (int i = 0; i < n.Size; i++) {
        		for (int j = 0; j < n.Size; j++) {
        			os<<n.gameTable[i][j].get();
        		} 
        	os<<endl;
        	}
        	return os;
        }

	istream& operator>> (istream& is, const Board& n){
        	for (int i = 0; i < n.Size; i++) {
        		for (int j = 0; j < n.Size; j++) {
        			is>>n.gameTable[i][j].get();
        		} 
        	//is>>endl;
        	}
        	return is;
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

	//draws a board of x and o as an image file
	string Board::draw(int n){
		const int dimx = n, dimy = n;
		int cellSize = n / this->size();
		int gridWidth = cellSize / this->size();
		int redC, greenC, blueC;
		string fileName = "board"+to_string(this->size())+".ppm";
		ofstream imageFile(fileName, ios::out | ios::binary);
		imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
		RGB image[dimx*dimy];
		//bg
		for (int j = 0; j < dimy; ++j)  {  // row
		  for (int i = 0; i < dimx; ++i) { // column
		     image[dimx*j+i].red = 234;
		     image[dimx*j+i].green = 233;
		     image[dimx*j+i].blue = 222;
		  }
		}
		for (int m = 0; m < this->size(); ++m)  {  // row
			for (int k = 0; k < this->size(); ++k) { // column
				char c = this->gameTable[m][k].get();
				switch(c){
					case '.':
						redC=greenC=blueC=0;
						break;
					case 'X':
						redC=234;
					    	greenC=0;
					    	blueC=59;
						break;
					case 'O':
					    	redC=0;
					   	greenC=163;
					   	blueC=82;
						break;
					default:
						cout << "ERROR, bad input" << endl;
				}
				if(c == '.'){ //draws instead of dot a square
					for (int i = m*cellSize+gridWidth; i < m*cellSize+cellSize-gridWidth; ++i)  {  // row
						for (int j = k*cellSize+gridWidth; j < k*cellSize+cellSize-gridWidth; ++j) { // column
						    image[dimx*i+j].red = redC;
						    image[dimx*i+j].green = greenC;
						    image[dimx*i+j].blue = blueC;
						}
					}
				}
				else if(c == 'X'){ //draws X
					int left=k*cellSize+gridWidth,right=k*cellSize+cellSize-gridWidth-1;
					int row=0;
					for (int i = m*cellSize+gridWidth; i < m*cellSize+cellSize-gridWidth; ++i)  {  // row
						//left
						image[dimx*i+left+row].red = redC;
						image[dimx*i+left+row].green = greenC;
						image[dimx*i+left+row].blue = blueC;
						//right
						image[dimx*i+right-row].red = redC;
						image[dimx*i+right-row].green = greenC;
						image[dimx*i+right-row].blue = blueC;
						row++;
					}
				}
				else{ // c == 'O', draws O
					double varY = m*cellSize+gridWidth, varX = k*cellSize+gridWidth;
					double y = varY/2+(m*cellSize+cellSize-gridWidth-1)/2, x = varX/2+(k*cellSize+cellSize-gridWidth-1)/2, radius = cellSize/2-2*gridWidth;
				    	for (int i = varY; i < m*cellSize+cellSize-gridWidth; ++i)  {  // row
				        	for (int j = varX; j < k*cellSize+cellSize-gridWidth; ++j) { // column
						    double d=pow(x-j,2)+pow(y-i,2);
						    d=sqrt (d);
						    d=abs(d-radius);
						    image[dimx*i+j].red = redC;
						    image[dimx*i+j].green = greenC;
						    image[dimx*i+j].blue = blueC;
				        	}
				    	}
				}
			}
		}
		
		///
		///image processing
		///
		imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
		imageFile.close();
		return fileName;

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



   



