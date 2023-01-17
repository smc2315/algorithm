#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
	string s;
	while (cin >> s)
	{
		bool check = true;
		if (s == "0")
			break;
		for (int i = 0; i < s.length()/2 +1; i++)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				check = false;
				break;
			}
		}
		if (check == true)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}