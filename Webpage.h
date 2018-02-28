#pragma once

#include <string>
using namespace std;

class Webpage {
public:
    Webpage();
    Webpage(const string& webpageURL, const time_t& timeVisited);
    string getURL();
    time_t getTime();
private:
	string webpage;
	time_t timeAccessed;

};
