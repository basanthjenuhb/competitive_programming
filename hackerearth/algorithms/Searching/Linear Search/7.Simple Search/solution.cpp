#include <iostream>

using namespace std;

int main()
{
	long int n, k, i, array[1000002];
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> array[i];
	cin >> k;
	for(i = 0; i < n; i++)
		if(array[i] == k)
			break;
	cout << i;
}
