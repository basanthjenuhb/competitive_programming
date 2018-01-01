#include <iostream>

using namespace std;

int main () {
	int N, k, count, weight;
	cin >> N;
	string str, subStr;
	while (N--) {
		cin >> k;
		cin >> str;
		count = 0;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 1; j < (str.length() - i + 1); j++) {
				subStr = str.substr(i, j);
				weight = 0;
				for (int l = 0; l < subStr.length(); l++) {
					weight += subStr[l] - 96;
				}
				if (weight == k) {
					count += 1;
				}
			}
		}
		cout << count << endl;
	}
}