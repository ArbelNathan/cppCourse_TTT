all//: Board.o Cell.o IllegalCharException.o IllegalCoordinateException.o
	 clang++-5.0 -std=c++17 main.cpp *.o

Board.o : 			Board.cpp
				clang++-5.0 -std=c++17 -c Board.cpp
Cell.o :			Cell.cpp
				clang++-5.0 -std=c++17 -c Cell.cpp
IllegalCharException.o :	IllegalCharException.cpp
				clang++-5.0 -std=c++17 -c IllegalCharException.cpp
IllegalCoordinateException.o :	IllegalCoordinateException.cpp
				clang++-5.0 -std=c++17 -c IllegalCoordinateException.cpp
 
