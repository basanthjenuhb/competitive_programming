#include <iostream>

using namespace std;

long long int leaf[100][3] = {0}, akatsuki[100][2] = {0};

int main () {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> akatsuki[i][0] >> akatsuki[i][1];
	}
	for (int i = 0; i < N; i++) {
		cin >> leaf[i][0] >> leaf[i][1];
	}
	int distance, calculatedDistance, totalDistance = 0, index = 0;
	for (int i = 0; i < N; i++) {
		distance = 999999999;
		index = -1;
		for (int j = 0; j < N; j++) {
			if (leaf[j][2] == 1) {
				continue;
			}
			calculatedDistance = abs(akatsuki[i][0] - leaf[j][0]) + abs(akatsuki[i][1] - leaf[j][1]);
			if (calculatedDistance < distance) {
				distance = calculatedDistance;
				index = j;
			}
		}
		leaf[index][2] = 1;
		totalDistance += distance;
	}
	cout << totalDistance << endl;
}