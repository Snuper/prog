#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
	int number_hex;
	long number_dec, temp_number_hex;
	string s;
	
	cin >> hex >> s;
	istringstream(s) >> hex >> number_hex;
	bitset<15> bits(number_hex);
	bits <<= 7;
	cout << bits << endl;
	cin >> hex >> s;
	istringstream(s) >> hex >> number_hex;
	bitset<15> temp_bits(number_hex);
	cout << endl << temp_bits << endl;
	bits ^= temp_bits;
	cout << endl << bits;
	
	return 0;
}
