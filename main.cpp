#include "Manifest.h"

int main()
{
	string first;
	string last;
	int number;
	Manifest pass;
	ifstream readFile;
	readFile.open("input.txt");

	readFile >> number;

	cout << "Welcome to Braden's Project #2!!!\n";
	while (!readFile.eof())
	{
		if (number == 1)
		{
			readFile >> first >> last;
			if (!pass.search(last, first)) {
				pass.insertHead(last, first);
				cout << first << " " << last << " booked!" << endl;
			}
			else
				cout << "Declined booking for " << first << " " << last << endl;
		}
		if (number == 2)
		{
			readFile >> first >> last;
			if (pass.search(last, first))
			{
				pass.deletename(last, first);
				cout << "Cancelled booking for " << first << " " << last << endl;
			}
			else
				cout << "Can not cancel booking for " << first << " " << last << endl;
		}
		if (number == 3)
		{
			readFile >> first >> last;
			if (!pass.search(last, first))
			{
				cout << "Could not find booking for " << first << " " << last << endl;
			}
			else
				cout << "Confirmed passenger " << first << " " << last << endl;
		}
		if (number == 4)
		{
			pass.sortList();
			pass.print();
		}
		if (number == 5)
		{
			break;
		}
		readFile >> number;
	}
	cout << "Thanks for using Braden's Airline Project!" << endl;
	readFile.close();

}