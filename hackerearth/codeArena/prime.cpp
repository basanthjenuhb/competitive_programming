# include <iostream>

using namespace std;

int numbers[1000001];

int isPrime(int n) {
    for (int i = 2; i < n/2 + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void markPrime() {
    for (int i = 2; i < 100; i++) {
        if (isPrime(i)) {
            numbers[i] = 1;
        }
    }
}

void printNumbers(int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << i << " : " << numbers[i] << "\n";
    }
}

int isPRIME(int left, int right) {
	int count, numOfPrimes = 0;
	for (int i = left; i <= right; i++) {
		count = 0;
		for (int j = 1; j <= i; j++) {
			count += numbers[j];
		}
		if (numbers[count]) {
			numOfPrimes++;
		}
	}
	return numOfPrimes;
}

int main() {
    markPrime();
    printNumbers(0,10);
	int testCases;
	cin >> testCases;
	while(testCases--) {
		int left, right;
		cin >> left >> right;
		cout << isPRIME(left, right);
	}
}