CXX=clang++-5.0
CXXFLAGS=-std=c++17

a.out: Board.o Cell.o IllegalCharException.o IllegalCoordinateException.o
		$(CXX) $(CXXFLAGS) main.cpp *.o

Board.o: Board.hpp Board.cpp
		$(CXX) $(CXXFLAGS) -c Board.cpp

Cell.o: Cell.hpp Cell.cpp
		$(CXX) $(CXXFLAGS) -c Cell.cpp

IllegalCharException.o: IllegalCharException.hpp
		$(CXX) $(CXXFLAGS) -c IllegalCharException.hpp

IllegalCoordinateException.o: IllegalCoordinateException.hpp
$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.hpp