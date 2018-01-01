#include <iostream>

using namespace std;

int main () {
	char matrix[100][100];
	int N, size, low, high, code, result;
	cin >> N;
	while (N--) {
		result = 0;
		cin >> size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> matrix[i][j];
			}
		}
		
		low = 0;
		high = size - 1;
		code = 1;
		while (low < high && code == 1) {
			for (int i = 0; i < size; i++) {
				if (matrix[low][i] != matrix[high][i]) {
					code = 0;
					break;
				}
			}
			low++;
			high--;
		}
		if (code == 1) {
			result++;
		}

		low = 0;
		high = size - 1;
		code = 1;
		while (low < high && code == 1) {
			for (int i = 0; i < size; i++) {
				if (matrix[i][low] != matrix[i][high]) {
					code = 0;
					break;
				}
			}
			low++;
			high--;
		}
		if (code == 1) {
			result += 2;
		}
		if (result == 0) {
			cout << "NO" << endl;
		} else if (result == 1) {
			cout << "HORIZONTAL" << endl;
		} else if (result == 2) {
			cout << "VERTICAL" << endl;
		} else if (result == 3) {
			cout << "BOTH" << endl;
		}
	}
} 