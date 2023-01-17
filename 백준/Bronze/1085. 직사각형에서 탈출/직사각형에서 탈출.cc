#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	int result = 10000;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((c - a) < result)
		result = c - a;
	if (a < result)
		result = a;
	if ((d - b) < result)
		result = d - b;
	if (b < result)
		result = b;
	cout << result;
	return 0;
}