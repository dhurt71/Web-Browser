#include "Webpage.h"

//Default Constructor for Webpage class.
Webpage::Webpage() {
	webpage = "";
	timeAccessed = 0;
}
//Creates a Webpage object and sets the variables
Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
	webpage = webpageURL;
	timeAccessed = timeVisited;
}
// returns the webpage
string Webpage::getURL() {
	return webpage;
}
// returns the timeAccessed
time_t Webpage::getTime() {
	return timeAccessed;
}
