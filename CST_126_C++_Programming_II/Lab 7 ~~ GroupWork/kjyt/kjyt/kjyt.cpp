#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file("C:\\Users\\kayleb.cook\\Downloads\\card.raw", ios::binary | ios::in);
	if (file.is_open()) {
			const unsigned char headerOne[4] = { 0xFF, 0xD8 , 0xFF , 0xE0 };
			const unsigned char headerTwo[4] = { 0xFF, 0xD8 , 0xFF , 0xE1 };
			unsigned char finFileheader[512];
			int numJPEGS = 0;
			int num = 0;
			
		while (!file.eof()) {
			file.read(reinterpret_cast<char*>(finFileheader), 512);

			if ((memcmp(headerOne, finFileheader, 4)) == 0 || (memcmp(headerTwo, finFileheader, 4)) == 0) {
				numJPEGS++;
			}
			else {

			}
		}
		cout << "There is " << numJPEGS << " JPEG files";
		file.close();
	}
}

