#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	multiset<int> ms;
	
	ms.insert(1);
	ms.insert(2);
	ms.insert(2);
	s.insert(1);
	s.insert(2);
	s.insert(2);
	
	cout << endl << "MS: " << ms.count(1) << endl;
	cout << endl << "S: " << s.count(1) << endl;
	
	return 0;
}
