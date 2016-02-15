#include <iostream>
using namespace std;
const unsigned int Converter[4] = {255 << 24, 255 << 16, 255 << 8, 255};

void convert(unsigned int &num)
{
	unsigned int result = 0;
	result |= (num & Converter[0]) >> 24;
	result |= (num & Converter[1]) >> 8;
	result |= (num & Converter[2]) << 8;
	result |= (num & Converter[3]) << 24;
	num = result;
}

int main(void)
{
	int n = 0;
	while(n < 1)
		cin >> n;

	unsigned int testCases[n];
	for(int i = 0; i < n; i++)
	{
		cin >> testCases[i];
		convert(testCases[i]);
	}

	for(int i = 0; i < n; i++)
		cout << testCases[i] << endl;

	return 0;
}
