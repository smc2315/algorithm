#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, input;
	cin >> a;
	
	while (a--)
	{
		cin >> input;
		int num = 0;
		while (input > 0)
		{
			
			if (input % 2 == 1)
				cout << num << " ";
			input = input / 2;
			num++;
		}
		cout << endl;
	}


}