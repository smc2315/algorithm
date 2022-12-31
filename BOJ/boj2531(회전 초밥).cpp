#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

int N, d, k, c;

int sushi[300001];
int check[3001];

int main()
{
	cin >> N >> d >> k >> c;
	
	for (int i = 0; i < N; i++) cin >> sushi[i];
    int result=0;
    int sum=0,coupon=0;
	for (int i = 0; i < N; i++)
	{
		sum = 0; 
		coupon = 1; 
		for (int j = i; j < i + k; j++) 
		{				
			if (check[sushi[j % N]] == 1) 
                sum++;	
			else 
                check[sushi[j % N]] = 1;	

			if (sushi[j % N] == c) 
                coupon = 0;
		}

		result = max(result, k - sum + coupon);	
		for(int j=0;j<3001;j++){
            check[j]=0;
        }
	}

	cout << result;
}
