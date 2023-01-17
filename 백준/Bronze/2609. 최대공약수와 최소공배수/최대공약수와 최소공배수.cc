#include <iostream>
#include <vector>

using namespace std;

int getgcd(int a, int b)
{
	if (b == 0)return a;
	else return getgcd(b, a%b);
}
int main()
{
	int a, b, gcd, lcm;
	cin >> a >> b;
	if (a > b)
		gcd = getgcd(a, b);
	else
		gcd = getgcd(b, a);
	lcm = a * b / gcd;
	cout << gcd << endl << lcm;

}