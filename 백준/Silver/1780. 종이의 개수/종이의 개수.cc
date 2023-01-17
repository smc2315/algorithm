#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int paper[2188][2188];
int result[3] = { 0, };

void find(int x, int y , int num)
{
	if (num < 1)
		return;
	int tmp = paper[x][y];
	bool check = true;
	for (int i = x; i <x+ num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			if (tmp != paper[i][j])
				check = false;
		}
	}
	if (check == true)
	{
		
		result[tmp + 1]++;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			find(x+(num/3)*(i/3), y+(i%3)*(num/3), num / 3);
		}
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			cin >> paper[i][j];
		}

	}
	find(0,0,N);
	cout << result[0] <<endl<< result[1] << endl << result[2];
	
	return 0;
}