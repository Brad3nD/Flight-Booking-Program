#include "Manifest.h"

Manifest::Manifest()
{
	head = NULL;
}
Manifest::~Manifest()
{

}

void Manifest::insertHead(string lname, string fname)
{
	Passenger *ptr = new Passenger(lname, fname);
	ptr->setNext(head);
	if (empty())
		tail = ptr;
	head = ptr;

}

void Manifest::insertTail(string lname, string fname)
{
	Passenger *ptr = head;
	while ((ptr != NULL) && (ptr->getNext() != NULL))
	{
		ptr = ptr->getNext();
	}
	if (ptr != NULL)
		ptr->setNext(new Passenger(lname, fname));
	else
		head = new Passenger(lname, fname);
	tail->setNext(ptr);
	tail = ptr;
}

bool Manifest::search(string lname, string fname)
{
	Passenger *current = head;
	while ((current != NULL) && (current->getFirst() != fname) && (current->getLast() != lname))
	{
		current = current->getNext();
	}
	if (current != NULL)
		return true;
	return false;
}

void Manifest::deletename(string lname, string fname)
{
	Passenger *current = head;
	Passenger *previous = head;
	while ((current != NULL) && (current->getFirst() != fname) && (current->getLast() != lname))
	{
		previous = current;
		current = current->getNext();
	}
	if (current == head)
		head = current->getNext();
	else
		previous->setNext(current->getNext());
	if (current == tail)
		tail = previous;
	delete current;
}

bool Manifest::empty()
{
	return (head == NULL);
}

void Manifest::print() 
{
	Passenger *ptr = head;
	while (ptr != NULL)
	{
		ptr->printPass();
		ptr = ptr->getNext();
	}
	cout << " x " << endl;
}

void Manifest::sortList()
{
	bool newl = false;
	bool unsorted = true;
	Passenger * cur1 = head;
	Passenger * cur2 = head->Next;
	Passenger *lowest = head;
	string templ, tempf;
	while (unsorted)
	{
		while (cur1 != NULL)
		{
			while (cur2 != NULL)
			{
				if (cur2->getLast() < lowest->getLast())
				{
					newl = true;
					lowest = cur2;
				}
				cur2 = cur2->Next;
			}
			if (newl) {
				tempf = lowest->getFirst();
				templ = lowest->getLast();
				lowest->setFirst(cur1->getFirst());
				lowest->setLast(cur1->getLast());
				cur1->setFirst(tempf);
				cur1->setLast(templ);
			}
			cur1 = cur1->Next;
			cur2 = cur1->Next;
			lowest = cur1;
			if (cur1 == tail)
				break;
		}
		unsorted = false;
	}
}