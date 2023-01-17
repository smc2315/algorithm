#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		float h, w, n;
		cin >> h >> w >> n;
		int floor;
		if (int(n) % int(h) == 0)
			floor = h;
		else
			floor = int(n) % int(h);
		cout << floor * 100 + ceil(n / h) << endl;

	}
	return 0;
}