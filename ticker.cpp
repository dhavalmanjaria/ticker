#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	using namespace std;

	ifstream in("/home/dhaval/Documents/TODO");

	string buf, fullString;
	vector<string> lines;



	while(in.good()) {
		getline(in,buf);
		lines.push_back(buf);
	}	
	in.close();


	unsigned int i = 0;
	while(cin.good()) {

		for (int i = 0; lines.size() > i; i++) {
			getline(cin,buf);
			fullString = lines[i] + " | " + buf;
			cout << fullString << endl;
			cout << flush;
		}
		
	}
}
