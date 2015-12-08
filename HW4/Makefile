phonebook : Person.o phonebook.o  
	g++ -ansi -Wall -g -o phonebook Person.o phonebook.o  

Person.o : Person.cpp 
	g++ -ansi -Wall -g -c Person.cpp

phonebook.o : phonebook.cpp 
	g++ -ansi -Wall -g -c phonebook.cpp

clean : 
	rm -f phonebook Person.o  phonebook.o   
