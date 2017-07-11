#include <iostream>
#include <cstdlib>
using namespace std;

int search(int transactions[],int target, int low, int high)
{
	int mid;
	while(low <= high)
	{
		mid = low + (high - low) / 2;
		if(transactions[mid] >= target && (mid == 0 || mid != 0 && transactions[mid - 1] < target))
				return mid + 1;
		if(transactions[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	int num, element;
	int transactions[100000];
	cin >> num;
	cin >> transactions[0];
	for(int i = 1; i < num; i++)
	{
		cin >> transactions[i];
		transactions[i] += transactions[i - 1];
	}
	int queries;
	int target;
	cin >> queries;
	while(queries--)
	{
		cin >> target;
		cout << search(transactions, target, 0, num - 1) << endl;
	}
}
