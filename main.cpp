#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
	using namespace std;
	
	string fileName;

	const string tempFileName = "/tmp/tickerFile";

	bool createTempFile = false;

	if (2 > argc) {
		cout << "Usage: ticker <fileName> [-r]" << endl << endl;
		return 0;
	} else {
		fileName = argv[1];
		if (3 == argc) {
			// If we need to refresh the file from the disk.
			if (0 == strcmp("-r", argv[2])) {
				createTempFile = true;
			}
		}
	}

	unsigned const int MAXCHARS = 100;
	ifstream is;
	
	// Section that reads file into a string
	string data; // string that will hold data

	int bufLen = 100;
	char *buf = new char[bufLen]; // buffer to hold each line

	is.open(tempFileName);
	if (!is) {
		is.open(fileName);
		createTempFile = true;
	}

	if (true == createTempFile) {
		while (is.good() && !is.eof()) {
			is.read(buf, MAXCHARS);
			data += buf;	
		}
		is.close();
		ofstream os(tempFileName);
		cout << data;
		os << data;
		os.close();		
	}

	if(is.good()) {
		while(!is.eof()) {
			is.getline(buf,MAXCHARS);
			data += buf;
			data += ' ';
		}
	} 
	is.close();

	delete[] buf;

		

	data += "       " ; // padding;

	// We modify the string to have a few spaces so that when it ends
	// we have some time to read the last part.

	// END OF FILE READ
	// This is where the fun begins

	// Section to get a call count.
	int callCount; // This variable records how many times the PROGRAM is called.
	is.open("/tmp/callCount");

	if (is.good()) {
		// The callCount File exists.
		is >> callCount;
		is.close();
	} else {
		callCount = 0;
		ofstream os("/tmp/callCount");
		os << callCount;
		os.close();
	}
	is.close();

	int charsToRead = callCount + MAXCHARS;
	int charsFromEnd = data.size() - MAXCHARS;
	for (unsigned i = callCount; i < charsToRead; i++)
		cout << data[i];

	if (charsFromEnd < charsToRead )
	{
		callCount = 0;
		ofstream os("/tmp/callCount");
		os << callCount;
		os.close();
	}


	callCount += 1;
	ofstream os("/tmp/callCount");
	os << callCount;
	os.close();
	return 0;
}
