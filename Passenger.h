#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Passenger
{
public:
	Passenger();
	Passenger(string lname, string fname);
	~Passenger();

	void setFirst(string fname);
	void setLast(string lname);
	void setNext(Passenger *next);
	void setNum(int num);

	string getFirst();
	string getLast();
	Passenger *getNext() ;
	int getNum();
	Passenger * Next;
	void printPass();

private:
	string firstName = "";
    string lastName = "";
	int commandNum = 0;
};
