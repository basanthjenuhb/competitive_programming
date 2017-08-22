#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, array[100002], k, j = 1;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> array[i];
	std::sort(array, array + n);
	cin >> k;
	if(j == k)
	{
	    cout << array[0];
	    exit(0);
	}
	for(int i = 0; i < n; i++)
	{
		if(array[i] == array[i + 1])
		{
			j++;
			if(j == k)
			{
				cout << array[i];
				break;
			}
		}
		else
			j = 1;
	}
}
