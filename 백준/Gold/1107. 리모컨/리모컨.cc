#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int arr[11] = { 0, };
int main()
{
	int n, m;
	cin >> n >> m;
	if (m == 10)
	{
		cout << abs(n - 100);
		return 0;
	}
	
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		arr[k]++;
	}
			
	
	int result = abs(n-100);
	for (int i = 0; i <= 1000000; i++)
	{
		bool check = true;
		string s = to_string(i);
		for(int j=0;j<s.length();j++)
        {
            if(arr[s[j]-'0'] !=0 )
            {
                check =false;
                break;
            }
        }
		
		if (check == true)
		{
			
			if (result > s.length() + abs(n - i))
				result = s.length() + abs(n - i);
		}
		
	}
	
	cout << result;
	return 0;
}