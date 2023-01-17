#include <iostream>
#include<vector>
#include <queue>

using namespace std;
vector<int> know;
vector<vector<int>> all(50);
int parent[51];
int n, m;

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return x = Find(parent[x]);
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	int num;
	cin >> num;
	while (num--) {
		int who;
		cin >> who;
		know.push_back(who);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int k;
		for (int j = 0; j < num; j++) {

			int tmp;
			if (j >= 1) {
				tmp = k;
				cin >> k;
				Union(tmp, k);
			}
			else {
				cin >> k;
			}
			all[i].push_back(k);


		}
	}
	int res = m;
	for (auto people : all)
	{
		bool flag = false;
		for (auto person : people)
		{
			if (flag)
				break;
			for (auto k : know)
			{

				if (Find(person) == Find(k))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			res--;
	}

	cout << res;

    return 0;
}
