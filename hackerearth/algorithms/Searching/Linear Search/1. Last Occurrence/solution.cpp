#include <iostream>
using namespace std;


void main(int args, char **argv)
{
	int element, n, m, pos = -1;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> element;
		if(element == m)
			pos = i + 1;
	}
	cout << pos;
}
