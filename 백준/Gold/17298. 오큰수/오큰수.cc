#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(N);
	stack<int> s;
	vector<int> nge(N , -1);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && v[s.top()] < v[i])
		{
			nge[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < N; i++)
		cout << nge[i] << " ";
	return 0;
	
	
}