# include <iostream>

using namespace std;

int main() {
	int characters[26] = {0};
	string word;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		if (!characters[word[i] - 97]) {
			characters[word[i] - 97] = 1;
			cout << word[i];
		}
	}
}