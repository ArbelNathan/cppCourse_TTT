
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

	istream& operator>> (istream& is,  Board& n){
        	
		string line;
		is>>line;
		int sizel=line.size();
		n.resize(sizel);
		int i=0;
		while(sizel--!=0){
        		for (int j = 0; j < line.size(); j++) {
        			n.gameTable[i][j].set(line[j]);
        		} 
		i++;
        	is>>line;	
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
		int gridWidth = cellSize /20;
		int redC, greenC, blueC;
		string fileName = "board"+to_string(this->size())+".ppm";
		ofstream imageFile(fileName, ios::out | ios::binary);
		imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
		RGB image[dimx*dimy];
		//bg
		for (int j = 0; j < dimy; ++j)  {  // row
		  for (int i = 0; i < dimx; ++i) { // column
		     image[dimx*j+i].red = 0;
		     image[dimx*j+i].green = 0;
		     image[dimx*j+i].blue = 0;
		  }
		}
		for (int m = 0; m < this->size(); ++m)  {  // row
			for (int k = 0; k < this->size(); ++k) { // column
				char c = this->gameTable[m][k].get();
				switch(c){
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
				}
				if(c == '.'){ //draws instead of dot a square
					
				}
				else if(c == 'X'){ //draws X
					int left=m*cellSize, right=k*cellSize;
					for (int i = (cellSize*0.10); i <(cellSize*0.90); ++i) {
						for (int j = 0; j <cellSize*0.01 ; ++j) {
						//left
						image[dimx*(i+left)+(i+(right))+j].red = redC;
						image[dimx*(i+left)+(i+(right))+j].green = greenC;
						image[dimx*(i+left)+(i+(right))+j].blue = blueC;
						//right
						image[dimx*(cellSize+left)-dimx*i+(i+right)+j].red = redC;
						image[dimx*(cellSize+left)-dimx*i+(i+right)+j].green = greenC;
						image[dimx*(cellSize+left)-dimx*i+(i+right)+j].blue = blueC;
						}
					}
				}
				
				else{// c == 'O', draws O			
				    int circle_radius=cellSize;
				    int xmid = cellSize/2.0;
				    int ymid = cellSize/2.0;
				    for (int i = 0; i <cellSize ; ++i) {
					for (int j = 0; j <cellSize ; ++j) {
						int tempx = i;
						int tempy = j;
						if(pow((((i-xmid)*(i-xmid)+(j-ymid)*(j-ymid)-(((cellSize)*0.45)*((cellSize)*0.45)))),2)<=pow(cellSize,2)){
							image[dimx*(i+m*cellSize)+(j+(k*cellSize))].green = redC;
							image[dimx*(i+m*cellSize)+(j+(k*cellSize))].red = greenC;
							image[dimx*(i+m*cellSize)+(j+(k*cellSize))].blue = blueC;
						}
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



   



