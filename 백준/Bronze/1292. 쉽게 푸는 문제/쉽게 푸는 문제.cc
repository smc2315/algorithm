#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a, b;
	int sum = 0;
	int arr[3000];
	int count = 1;
	cin >> a >> b;
	int i = 0;
	while (i <= 1000)
	{
		for (int j = 0; j < count; j++)
		{
			arr[i + j] = count;
		}
		i = i + count;
		count++;

	}
	
	for (int i = a - 1; i < b; i++)
	{
		sum += arr[i];
	}

	cout << sum;
	return 0;
}