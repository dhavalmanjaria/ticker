#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace std;

	string fileName;

	if (argc != 2) {
		cout << "Usage: " << endl;
		cout << "\ti3status | ticker <fileName>" << endl;
		return 0;
	} else {
		fileName = argv[1];
	}

	ifstream in(fileName);

	string buf, fullString;
	vector<string> lines;

	while(in.good()) {
		getline(in,buf);
		lines.push_back(buf);
	}	
	in.close();


	while(cin.good()) {

		for (unsigned int i = 0; lines.size() > i; i++) {
			getline(cin,buf);
			fullString = lines[i] + " | " + buf;
			cout << fullString << endl;
			cout << flush;
		}
		
	}
}
