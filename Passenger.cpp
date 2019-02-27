#include "Passenger.h"

Passenger::Passenger()
{
	firstName = "";
	lastName = "";
	Next = NULL;
}

Passenger::Passenger(string lname, string fname)
{
	firstName = fname;
	lastName = lname;
}

Passenger::~Passenger()
{

}

void Passenger::setFirst(string fname)
{
	firstName = fname;
}

void Passenger::setLast(string lname)
{
	lastName = lname;
}

void Passenger::setNext(Passenger *next)
{
	Next = next;
}

void Passenger::setNum(int num)
{
	commandNum = num;
}

string Passenger::getFirst()
{
	return firstName;
}

string Passenger::getLast()
{
	return lastName;
}

Passenger *Passenger::getNext()
{
	return Next;
}

int Passenger::getNum()
{
	return commandNum;
}

void Passenger::printPass()
{
	cout << getFirst() << " " << getLast() << " -> ";
}