#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

unsigned const char MAXCHARS = 100;
// This defines the maximum characters we show, and we also use this
// value for a buffer size.

string readFile(string fileName, string tempFileName) ;

int main()
{
	string data = readFile("/home/dhaval/Documents/TODO", "/tmp/tickerFile");

	cout << data;
}

string readFile(string fileName, string tempFileName) 
{

	string data = ""; // Our return value

	ifstream is(tempFileName);
	
	if (!is.good()) {
		// The temp file doesn't exist. 
		// We simply read the data and store it into the file.
		is.close();
		is.open(fileName);

		is.seekg(0, is.end);
		int len = is.tellg();
		is.seekg(0,is.beg);
		// Get length of file.
		//
		char * buf = new char[len];
		if(is.good()) {
			while(!is.eof()) {
				is.read(buf, len);
			}
			is.close();
			buf[len] =  '\0';

			data = buf;
		}

	} else {
		// Temp file does not exist.
	}

	
	return data;
}
