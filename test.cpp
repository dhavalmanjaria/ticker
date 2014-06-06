#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	using namespace std;
	const int len = 100;

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
		getline(cin,buf);

		if (lines.size() <= i)
			i = 0;
		else
			i++;

		fullString = lines[i] + " | " + buf;
		cout << fullString << flush;

		cout << "\033[2K" << flush;
		cout << "\033[U";
	}
	
}
