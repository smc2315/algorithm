#include <iostream>
#include <string>
using namespace std;
int video[65][65] ;

void zip(int x, int y, int num)
{
	bool check = true;
	int tmp = video[x][y];
	for (int i = x; i < x + num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			if (video[i][j] != tmp)
			{
				check = false;
				break;
			}
		}
		if (check == false)
			break;
	}
	
	if (check == false)
	{
		cout << "(";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				zip(x+i*(num / 2), y+j*(num / 2), num / 2);
		cout << ")";
	}
	else
		cout << tmp;
}
int main() 
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			video[i][j] = s[j] - '0';
		}
	}
	zip(0, 0, N);
	
	
	return 0;
}