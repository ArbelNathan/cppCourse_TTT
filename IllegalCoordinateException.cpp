
using namespace std;
#include "IllegalCoordinateException.hpp"

	IllegalCoordinateException::IllegalCoordinateException(int x, int y){ this->corX = x; this->corY = y;}
		
	string IllegalCoordinateException::theCoordinate() const{ 
			return to_string(corX) + "," + to_string(corY);
		}