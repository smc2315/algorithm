#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;
int a, b, c;
long long pow(int x,int y) {
	if (y == 0)
		return 1;
	else if (y == 1)
		return x;
	
	if (y % 2 == 1) {
		return pow(x, y-1)*x;
	}
	long long half = pow(x, y / 2);
	half %= c;
	return (half*half) % c;
	

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> a >> b >> c;
	cout<<pow(a,b)%c;
	
	return 0;
}