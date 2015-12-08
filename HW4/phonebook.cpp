//Haaris Mirza  



#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include "Person.h"
#include <set>
#include <iomanip>
#include <iterator>
#include <algorithm>

using namespace std;

//checks is the # of command line args are fine
void check_args(int argc)
{
    if (argc != 2)
    {
        cout << "file not found" << endl;
        exit(1);

    }
}


//accepts first line as parameter and splits the line into tokens
set<Person> tokenize(string line, set<Person> s, string &last, string &first, string &num)
{


    char * cstr = new char [line.length() + 1];
    strcpy (cstr,line.c_str());
    char * p = strtok (cstr, " ");
    
    last = string(p);
  
    p = strtok (0," ");
    
    first = string(p);

    p = strtok (0, " ");
  
    num = string(p);
    
    delete[] cstr; 

    return s;

}


int main(int argc, char* argv[])
{

    /*
    set <Person> test;

    Person pers1("delevigne", "cara", "190-109-9292");

    Person pers2("adams", "micahael","280-983-9093");

    Person pers3("hello", "poop", "280-983-9093");

    Person pers4("hello", "sldkjf", "786-789-7890");

    test.insert(pers1);
    test.insert(pers2);
    test.insert(pers3);
    test.insert(pers4);


    for ( set<Person>::iterator i = test.begin(); i != test.end(); i++ )
        {
               cout << *i;
               cout << '\n';      
        }

    */
    //check if there are right amount of command line args
    check_args(argc);

    char* list = argv[1];
    ifstream filename;
    filename.open(list); //open file

    string line,last,first,num; //vars to be passed through functions
    set<Person> s;
   
    if (filename.is_open())
    {

        while (getline (filename, line)) //get each line
        {
      
            tokenize(line, s, last,first,num); //tokenize and assign to referenced vars
            Person pers(last, first, num); //call to constructor/go through checks
            s.insert(pers); //insert to set 
            
        }

        for (set<Person>::iterator i = s.begin(); i != s.end(); i++) //print out set
        {
               cout << *i;
               cout << '\n';      
        }
        
        
    }

    filename.close();

}
