#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

int N, d, k, c;
int flag, cnt, coupon, maxi = 0;
int sushi[300001];
int check[3001];
vector<int> eat;

int main()
{
	cin >> N >> d >> k >> c;
	
	for (int i = 0; i < N; i++) cin >> sushi[i];


	for (int i = 0; i < N; i++)
	{
		flag = 0; 
		coupon = 1; 
		for (int j = i; j < i + k; j++) 
		{				
			if (check[sushi[j % N]] == 1) flag++;	
			else check[sushi[j % N]] = 1;	

			if (sushi[j % N] == c) coupon = 0;
		}

		maxi = max(maxi, k - flag + coupon);	
		for(int j=0;j<3001;j++){
            check[j]=0;
        }
	}

	cout << maxi;
}