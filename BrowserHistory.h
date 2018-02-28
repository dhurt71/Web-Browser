#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
//#include <list>
using namespace std;

struct CurrentNode {
	string data;
	time_t timestamp;
	CurrentNode* next;
	CurrentNode* prev;
};

struct FullNode {
	string dataFull;
	time_t timeFull;
	FullNode* nextFull;
};

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();

    void visitSite(Webpage newSite);
    string back();
    string forward();

    void readHistory(string fileName);

    string getURL();
    size_t getNavSize();

    void printBackSites();
    void printForwardSites();
    void printFullHistory();

private:
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions

	CurrentNode* head;
	CurrentNode* nodeptr;
	FullNode* headFull;
	FullNode* nodeptrFull;
	int size;
	int fullsize;
};
