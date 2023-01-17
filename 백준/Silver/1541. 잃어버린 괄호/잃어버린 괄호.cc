#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	string tmp = "";
	cin >> s;
	bool isminus = false;
	int result = 0;
	for (int i = 0; i <= s.length(); i++)
	{

		if (s[i] == '+' || s[i] == '-' || s[i] == NULL)
		{
			if (isminus == true)
			{
				result -= stoi(tmp);
				tmp = "";
			}
			else
			{
				result += stoi(tmp);
				tmp = "";
			}

		}
		else
			tmp += s[i];
		if (s[i] == '-')
			isminus = true;
	}
	cout << result;

	return 0;
}