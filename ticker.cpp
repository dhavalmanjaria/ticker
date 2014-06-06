#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace std; // Make things easier

	string fileName; // Filename of the file to be read from

	if (argc != 2) {
		cout << "Usage: " << endl;
		cout << "\ti3status | ticker <fileName>" << endl;
		return 0;
	} else {
		fileName = argv[1];
	}

	ifstream in(fileName);

	string buf;
	// buf will hold the output from i3status
	
	vector<string> lines;
	// This will hold all the lines from the file

	while(in.good()) {
		getline(in,buf);
		lines.push_back(buf);
	}	
	in.close();
	// We do this so that we don't read the file each time we tick.


	while(cin.good()) {
		for (unsigned int i = 0; lines.size() > i; i++) {
			getline(cin,buf); // Get i3status input into a line
			cout << lines[i] << " | " << buf;
			cout << flush; // flush output so that it's shown immediately.
		}
		
	}
}
