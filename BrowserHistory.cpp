#include "BrowserHistory.h"
#include <iostream>

//Default constructor for the Browser History class
BrowserHistory::BrowserHistory() {
	head = nullptr;
	nodeptr = nullptr;
	fullsize = 0;
	size = 0;
	headFull = NULL;
	nodeptrFull = NULL;
}

//Deletes the Broswer History class
BrowserHistory::~BrowserHistory() {
	CurrentNode* nodeptr = head;
	FullNode* nodeptrFull = headFull;

	while (nodeptr != nullptr) {
		nodeptr = nodeptr->next;
		delete head;
		head = nodeptr;
	}
	while (nodeptrFull != NULL) {
		nodeptrFull = nodeptrFull->nextFull;
		delete headFull;
		headFull = nodeptrFull;
	}

}
//adds a webpage to both the current history and full history linked lists
void BrowserHistory::visitSite(Webpage newSite) {
	if (head == nullptr) {
		head = new CurrentNode;
		head->data = newSite.getURL();
		head->timestamp = newSite.getTime();
		head->prev = nullptr;
		head->next = nullptr;
		nodeptr = head;
		size++;
	}
	else {
		if (nodeptr->next != NULL) {
			CurrentNode* temp = nodeptr;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			while (temp != nodeptr) {
				temp = temp->prev;
				delete temp->next;
				temp->next = nullptr;
				size--;
			}
		}
		CurrentNode* a = new CurrentNode;
		a->data = newSite.getURL();
		a->timestamp = newSite.getTime();
		nodeptr->next = a;
		a->prev = nodeptr;
		nodeptr = a;
		a->next = nullptr;
		size++;
	}

	if (headFull == NULL)
	{
		headFull = new FullNode;
		headFull->dataFull = newSite.getURL();
		headFull->timeFull = newSite.getTime();
		headFull->nextFull = nullptr;
		nodeptrFull = headFull;
	}
	else {
		FullNode* b = new FullNode;
		b->dataFull = newSite.getURL();
		b->timeFull = newSite.getTime();
		nodeptrFull->nextFull = b;
		nodeptrFull = b;
		b->nextFull = nullptr;
	}
	fullsize++;
}
//Returns the url from linked list
string BrowserHistory::getURL() {
	return nodeptr->data;
}
//returns the size of the linked list
size_t BrowserHistory::getNavSize() {
	return size;
}
//goes back in the current history linked list
string BrowserHistory::back() {
	nodeptr = nodeptr->prev;
	return nodeptr->data;
}
//goes forward in the current history linked list
string BrowserHistory::forward() {
	nodeptr = nodeptr->next;
	return nodeptr->data;
}
//reads in a file
void BrowserHistory::readHistory(string fileName) {
	ifstream myfile(fileName);

	if (myfile.is_open()) {
		string webpageholder;
		time_t timeholder;
		string holder;

		cout << "Successfully opened file " << fileName << endl;
		while (myfile >> holder) {
			if (holder == "new") {
				myfile >> webpageholder >> timeholder;
				Webpage newpage(webpageholder, timeholder);
				visitSite(newpage);
			}	
			else if (holder == "back") {
				back();
			}
			else {
				forward();
			}
		}
	}
	else
		throw invalid_argument("Could not open file " + fileName);
}
//Prints everything in the current history's back portion of the linked list
void BrowserHistory::printBackSites() {
	CurrentNode* backtravel = new CurrentNode;
	backtravel = head;
	while (backtravel != nodeptr)
	{
		cout << backtravel->data << endl;
		backtravel = backtravel->next;
	}
}
//Prints everything in front of the current spot in the current history's linked list
void BrowserHistory::printForwardSites() {
	if (nodeptr->next == NULL)
		return;
	CurrentNode* fronttravel = new CurrentNode;
	fronttravel = nodeptr;
	for (int i = fullsize; i > size+1; i--)
	{
		cout << fronttravel->data << endl;
		fronttravel = fronttravel->next;
	}
}
//Prints the entire browser history
void BrowserHistory::printFullHistory() {
	FullNode *traversal = new FullNode;
	traversal = headFull;
	while (traversal != NULL)
	{
		cout << traversal->dataFull << endl;
		traversal = traversal->nextFull;
	}
}
