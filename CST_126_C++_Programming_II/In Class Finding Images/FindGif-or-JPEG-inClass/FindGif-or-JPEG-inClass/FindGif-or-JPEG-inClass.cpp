#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char**argv)
{
	ifstream hootie(argv[1]);
	if (hootie.is_open()) {
		const unsigned char gifHeader[6] = { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61 };
		unsigned char finFileheader[6];
		hootie.read(reinterpret_cast<char*>(finFileheader), 6);
		if (memcmp(gifHeader, finFileheader, 6) == 0) {
			cout << "This is a GIF file." << endl;
		}

		else {
			cout << "This isn't a GIF file." << endl;
		}
	}
	else {
		cout << "Couldnt open file" << endl;
	}
}

//to put in file argument straight into the file, 
// copy the source code, 
// then debug (in the top menu bar) -> 
// debug properties (last option in dropdown menu) -> 
// debugging -> 
// then paste into command arguments