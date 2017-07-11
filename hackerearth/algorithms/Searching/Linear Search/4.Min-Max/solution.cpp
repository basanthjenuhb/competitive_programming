#include <iostream>
#include <limits.h>
using namespace  std;

int main()
{
	int size;
	int element, sum = 0, min = INT_MAX, max = 0, new_num;
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cin >> element;
		sum += element;
		if(element > max)
			max = element;
		if(element < min)
			min = element;
	}
	cout << sum - max << " " << sum - min << "\n";
}
