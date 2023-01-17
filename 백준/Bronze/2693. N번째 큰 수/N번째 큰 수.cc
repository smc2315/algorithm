#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int arr[10];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[j];
		sort(arr,arr+10, greater<int>());
		cout << arr[2] << endl;
	}

}