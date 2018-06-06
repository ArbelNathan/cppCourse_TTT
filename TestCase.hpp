#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
#pragma once

class TestCase{
	private:
		string s;
	public:
		TestCase(string, ostream&);   // constructor
		check_equal(int,int)  ;       // check operator ==. 
		check_different(int,int);     // check operator !=. 
		check_function(function, int,int); // check a function int->int.
		check_output(int, string);    // check output operator <<
		print();                      // check how many tests faild / succeeded

};
