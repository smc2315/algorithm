#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
	int n;
	int cnt = 0;
	string s;
	int c = 665;
	cin >> n;
	while (c++)
	{
		s = to_string(c);
		if (s.find("666") != -1)
			cnt++;
		if (cnt == n)
		{
			cout << c<<endl;
			break;
		}
	}


	return 0;
}