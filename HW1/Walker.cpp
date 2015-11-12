// Name: Haaris Mirza
// ID: 912341213
// File: Walker.cpp



#include "Walker.h"
#include <iostream>
using namespace std;

//constructor 
Walker::Walker (int a, int b) 
{
	x = a;
	y = b;
}

//constructor
Walker::Walker ()
{
	x=0;
	y=0;
}


//move by method
void Walker::move_by (int a, int b)
{
	x = x + a;
	y = y + b;

	if (x > 10 || x < -10)
	{
		throw invalid_argument("outside of domain");
	} 

	if (y > 10 || y < -10)
	{
		throw invalid_argument("outside of domain");
	}		
}

//overloaded operator
Walker& Walker::operator= (const Walker &w)
{
	if (&w == this)
		return *this;
	x = w.x;
	y = w.y;

	return *this;
}


//Overloaded Operator
istream &operator>>(istream &input, Walker &w)
{
	input >> w.x >> w.y;

	return input;
}

//Overloaded Operator
ostream &operator<<(ostream &output, Walker &www)
{
	output << "(" << www.x << "," << www.y << ")";

	return output;
}

//get x
int Walker::get_x()
{	
	return x;
}

//get y
int Walker::get_y()
{
	return y;
}

