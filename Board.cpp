
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
		string fileName = "board"+to_string(this->size())+".ppm"; // so it wont override the current file, it makes a new one according to its size
		ofstream imageFile(fileName, ios::out | ios::binary);
		imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
		RGB image[dimx*dimy];
		//bg
		for (int j = 0; j < dimy; ++j)  {  // row
		  for (int i = 0; i < dimx; ++i) { // column
		     image[dimx*j+i].red = 255;
		     image[dimx*j+i].green = 255;
		     image[dimx*j+i].blue = 255;
		  }
		}
		for (int m = 0; m < this->size(); ++m)  {  // row
			for (int k = 0; k < this->size(); ++k) { // column
				char c = this->gameTable[m][k].get(); // every sign gets different color
				switch(c){
					case '.':
						redC=greenC=blueC=0;
						break;
					case 'X':
						redC=200;
					    	greenC=255;
					    	blueC=255;
						break;
					case 'O':
					    	redC=255;
					   	greenC=100;
					   	blueC=255;
						break;
					default:
						cout << "ERROR, bad input" << endl;
				}
				//****ארבל זה בשבילך , איפה שנתקעתי: אמור לעשות את הצורות כאן ****
				if(c == '.' || c == 'X'){
					int left=k*cellSize+gridWidth,right=k*cellSize+cellSize-gridWidth-1;
					int row=0;
					for (int i = m*cellSize+gridWidth; i < m*cellSize+cellSize-gridWidth; ++i)  {  // row
						for (int j = k*cellSize+gridWidth; j < k*cellSize+cellSize-gridWidth; ++j) { // column
						    image[dimx*i+j].red = (redC);
						    image[dimx*i+j].green = (greenC);
						    image[dimx*i+j].blue = (blueC);
						}
						//left
						image[dimx*i+left+row].red = (redC);
						image[dimx*i+left+row].green = (greenC);
						image[dimx*i+left+row].blue = (blueC);
						//right
						image[dimx*i+right-row].red = (redC);
						image[dimx*i+right-row].green = (greenC);
						image[dimx*i+right-row].blue = (blueC);
						row++;
					}
				}
				else{ // c == 'O'
					double  p = m*cellSize+gridWidth, l = k*cellSize+gridWidth , d;
					double  y = p/2+(p-gridWidth-1)/2, x = l/2+(l-gridWidth-1)/2, radius = cellSize/2-2*gridWidth;
					for (int j = p; j < m*cellSize+cellSize-gridWidth; ++j)  {  // row
						for (int i =l; i < k*cellSize+cellSize-gridWidth; ++i) { // column
							d=pow(x-j,2)+pow(y-i,2);
							d=sqrt (d);
							d=abs(d-radius);
							image[dimx*j+i].red = (redC);
							image[dimx*j+i].green = (greenC);
							image[dimx*j+i].blue = (blueC);
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



   



