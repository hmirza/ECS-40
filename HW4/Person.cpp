//Haaris Mirza
//912341213

#include "Person.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <string.h>
#include <algorithm>



using namespace std;

//constructor
Person::Person(string last, string first, string num) : lastname_(last), firstname_(first), number_(num)
{

	int i = 0;
	while (last[i])
	{
		if (!isalpha(last[i]))
		{
			
			cout << "invalid characters in last name" << '\n';
			exit(1);


		}
		i++;
	}

	//first name check
	int j = 0;
	while (first[j])
	{
		if (!isalpha(first[j]))
		{ 
			cout << "invalid characters in first name" << '\n';
			exit(1);
		}
		j++;
	}

	//number format check
	int k = 0;
	while (num[k])
	{
		if(num[3] != '-' || num[7] != '-')
		{
			cout << "invalid number format";
			exit(1);
		}

		if (!isdigit(num[0]) || !isdigit(num[1]) ||
			!isdigit(num[2]) || !isdigit(num[4]) ||
			!isdigit(num[5]) || !isdigit(num[6]) ||
			!isdigit(num[8]) || !isdigit(num[9]) ||
			!isdigit(num[10])|| !isdigit(num[11]))

		{
			cout << "invalid number format";
			exit (1);
		}
		k++;
	}

}

//get lastname
string Person::lastname(void) const
{
	return lastname_;
}

//get first name
string Person::firstname(void) const
{
	return firstname_;
}

//get number
string Person::number(void) const
{
	return number_;
}

//comparison when last name are equal, sort by first name
bool Person::operator<(const Person& p) const
{


	if(lastname() == p.lastname() && !(firstname() == p.firstname()))
	{
		return  firstname() < p.firstname() ;
	}

	return  lastname() < p.lastname() ;


}

//overloaded operator to cout opject
ostream& operator<< (ostream& os, const Person& p)
{

	os << left << setw(15) << p.lastname();
	os << setw(15) << p.firstname();
	os << setw(12) << p.number();

	
	return os;
}