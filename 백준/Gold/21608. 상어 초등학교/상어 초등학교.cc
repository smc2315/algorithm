#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info {
	int x, y,liken = 0, voidn = 0;
};

struct operate {
	bool operator()(info n1, info n2)
	{
		if (n1.liken == n2.liken)
		{
			if (n1.voidn == n2.voidn)
			{
				if (n1.x == n2.x)
					return n1.y > n2.y;
				return n1.x > n2.x;
			}
			return n1.voidn < n2.voidn;
		}
		return n1.liken < n2.liken;
	}
};

struct student {
	int num;
	int like[4];
	int x, y;
};

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	int n;
	int table[20][20] = { 0, };
	cin >> n;
	vector<student> s(n*n);
	for(int i = 0; i< n*n;i++)
	{
		priority_queue<info, vector<info>, operate> pq;
		
		info inf;
		cin >> s[i].num;
		for (int j = 0; j < 4; j++)
		{
			cin >> s[i].like[j];
		}
		for (int k = 0; k < n; k++)
		{
			for (int l = 0; l < n; l++)
			{
				if (table[k][l] == 0)
				{
					int nx, ny;
					inf.liken = 0, inf.voidn = 0;
					inf.x = k, inf.y = l;
					for (int m = 0; m < 4; m++)
					{
						if (k + dx[m] >= 0 && k + dx[m] < n && l + dy[m] >= 0 && l + dy[m] < n)
						{
							nx = k + dx[m];
							ny = l + dy[m];
							for (int ii = 0; ii < 4; ii++)
							{
								if (table[nx][ny] == s[i].like[ii])
									inf.liken++;
								else if (table[nx][ny] == 0)
									inf.voidn++;
							}
							
						}
					}
					pq.push(inf);
				}
			}
		}
		if (!pq.empty())
		{
			int x = pq.top().x;
			int y = pq.top().y;

			table[x][y] = s[i].num;
			s[i].x = x;
			s[i].y = y;
		}

	}
	int total = 0;
	for (int i = 0; i < n * n; i++)
	{
		int good = 0;
		for (int j = 0; j < 4; j++)
		{
			if (s[i].x + dx[j] >= 0 && s[i].x + dx[j] < n && s[i].y + dy[j] >= 0 && s[i].y + dy[j] < n)
			{
				int nx = s[i].x + dx[j];
				int ny = s[i].y + dy[j];
				for (int k = 0; k < 4; k++)
				{
					if (table[nx][ny] == s[i].like[k])
						good++;

				}
			
			}
		}
		if (good == 0)
			total += 0;
		else if (good == 1)
			total += 1;
		else if (good == 2)
			total += 10;
		else if (good == 3)
			total += 100;
		else if (good == 4)
			total += 1000;
	}

	cout << total << endl;


}