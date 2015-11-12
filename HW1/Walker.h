// Name: Haaris Mirza
// ID: 912341213
// File: Walker.h

#ifndef WALKER_H_
#define WALKER_H_

#include <iostream>
#include <cmath>
#include <stdexcept> 
using namespace std;

class Walker
{
	
public:


	//Operator Overload
	friend istream &operator>>(istream &, Walker &);
	friend ostream &operator<<(ostream &, Walker &);
	Walker(); //constructor 
	Walker (int, int); //constructor with intialized variables
	void move_by(int, int); //move_by method
	int get_x(); //get x variable method because variables are in private
	int get_y(); //get y variable method because variables are in private
	Walker& operator=(const Walker &w);

private:
	int x;
	int y;

};


#endif

