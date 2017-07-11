#include <iostream>
#include <cstdlib>
using namespace std;

inline bool date(string dayInString)
{
	int day = atoi(dayInString.c_str());
	if(day == 19 || day == 20)
		return true;
	return false;
}

inline bool isDigit(char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	return false;
}

void weightedSum(string message, int weight, int &isDate, int &isNotDate)
{
	for(int i = 1; i < message.length(); i++)
	{
		if(isDigit(message[i]))
		{
			int k = i, j = 1;
			while(isDigit(message[i++]) && j++);
			if(date(message.substr(k, j - 1)))
				isDate += weight;
			else
				isNotDate += weight;
		}
	}
}

void process(string message, int &isDate, int &isNotDate)
{
	if(message[0] == 'G')
		weightedSum(message, 2, isDate, isNotDate);
	else
		weightedSum(message, 1, isDate, isNotDate);
}

int main()
{
	int lines, isDate = 0, isNotDate = 0;
	string message;
	cin >> lines;
	lines++;
	while(lines--)
	{
		getline(cin, message);
		process(message, isDate, isNotDate);

	}
	if(isDate > isNotDate)
		cout << "Date";
	else
		cout << "No Date";
	cout << "\n";
}
