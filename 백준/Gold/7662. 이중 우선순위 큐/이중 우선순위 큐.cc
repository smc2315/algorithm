#include <iostream>
#include <set>
#include <algorithm>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		multiset<int> v;
		for (int j = 0; j < m; j++)
		{
			
			char c;
			int k;
			cin >> c >> k;
			if (c == 'I')
			{
				v.insert(k);
				

			}
			else
			{
				if (v.empty())
					continue;
				else if (k == 1)
				{
					v.erase(--v.end());
				}
				else
				{
					v.erase(v.begin());
				}
			}
		
		}
		if (v.empty())
		{
			cout << "EMPTY" << endl;
		}
		else
			cout << *--v.end() << " " << *v.begin() << "\n";
		
		
	}
	return 0;
}