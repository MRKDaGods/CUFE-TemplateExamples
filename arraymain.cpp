#include <iostream>

#include "Array.h"

using namespace std;

int main() 
{
	Array<int> a1;
	cin >> a1;

	Array<int> a2;
	cin >> a2;

	cout << (a1 == a2) << endl;

	return 0;
}