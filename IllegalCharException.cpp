
using namespace std;
#include "IllegalCharException.hpp"

	IllegalCharException::IllegalCharException(char a){c = a;}

    char IllegalCharException::theChar() const{ 
			return c;
		}