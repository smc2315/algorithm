#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int r, c;
int result = 0;
void find(int xs, int xe, int ys, int ye)
{
	
	if (xe - xs <= 1)
		return;
	if (r < xs+(xe - xs) / 2 && c < ys+(ye - ys) / 2)
	{
		find(xs, xs+(xe - xs) / 2, ys, ys+(ye - ys) / 2);
	}
	else if (r < xs+(xe - xs) / 2 && c >= ys+(ye - ys) / 2)
	{
		result += (xe - xs)*(xe - xs) / 4;
		find(xs, xs+(xe - xs) / 2, ys+(ye - ys) / 2, ye );
		
	}
	else if (r >= xs+(xe - xs) / 2 && c < ys+(ye - ys) / 2)
	{
		result += (xe - xs)*(xe - xs) / 2;
		find(xs+(xe - xs) / 2, xe , ys, ys+(ye - ys) / 2);
		
	}
	else
	{
		result += (xe - xs)*(xe - xs) / 4 * 3;
		find(xs+(xe - xs) / 2, (xe), ys+(ye - ys) / 2, ye);
		
	}

}

int main()
{
	int n;
	cin >> n>>r>>c;
	find(0,pow(2,n),0,pow(2,n));
	cout << result;
	return 0;
}