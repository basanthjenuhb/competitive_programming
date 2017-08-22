#include <iostream>
#include <string>
using namespace std;

int searchFor21(int k)
{
	if(!(k % 21))
		return 0;
	if(to_string(k).find("21") != string::npos)
		return 0;
	return 1;
}

int main()
{
	int n, k;
	cin >> n;
	while(n--)
	{
		cin >> k;
		if(searchFor21(k))
			cout << "The streak lives still in our heart!\n";
		else
			cout << "The streak is broken!\n";
	}
}
