#include "Passenger.h"
class Manifest
{
public:
	Manifest();
	~Manifest();

	void insertHead(string lname, string fname);
	void insertTail(string lname, string fname);
	bool search(string lname, string fname);
	void deletename(string lname, string fname);
	bool empty();
	void sortList();

	void print();

private:
	Passenger * head;
	Passenger * tail;
};
