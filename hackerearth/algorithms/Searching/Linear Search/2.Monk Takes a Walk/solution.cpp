#include <iostream>
using namespace std;

int isVowel(char ch)
{
	switch(ch)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':return 1;
		default:return 0;
	}
}

int getVowelCount(string str)
{
	int count = 0;
	for(int i = 0; i < str.length(); i++)
		if(isVowel(str[i]))
			count++;
	return count;

}

int main()
{
	int N;
	string str;
	cin >> N;
	while(N--)
	{
		cin >> str;
		cout << getVowelCount(str) << endl;
	}
}
