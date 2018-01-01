#include <iostream>

using namespace std;

long long int cube(int number) {
	long long int result = 1;
	result = result * number * number * number;
	return result;
}

int getJhool (int number) {
	long long int result;
	int count;
	int left, right;
	for (int i = number; i > 0; i--) {
		count = 0;
		left = 1;
		right = i;
		while (left <= right) {
			result = cube(left) + cube(right);
			if (result == i) {
				count++;
				left++;
				result--;
			}
			if (count == 2) {
				return i;
			}
			if (result < i) {
				left++;
			}
			if (result > i) {
				right--;
			}
		}
	}
	return -1;
}

int main () {
	int testCases;
	cin >> testCases;
	int number;
	while (testCases--) {
		cin >> number;
		cout << getJhool(number) << endl;
	}
}
