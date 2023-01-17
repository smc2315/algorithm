#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int a,b,v;
	cin >> a>> b>> v;
	int result;
	result = ceil((float)v / (float)(a - b));
	while (1)
	{
		
		if (result*(a-b) + (2 * b) - a >= v)
			result -= 1;
		else
			break;
		
	}
	cout << result;
	return 0;
}