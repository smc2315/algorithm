#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> v[100000];
int visited[100001];

bool dfs(int num) {
	
	stack<int> stk;
	stk.push(num);
	visited[num] = true;
	while (!stk.empty()) {
		int cur = stk.top();
		//cout << cur << endl;
		
		stk.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (!visited[v[cur][i]]) {
				stk.push(v[cur][i]);
				visited[v[cur][i]] = cur;

			}
		}
	}
	return false;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << visited[i] << "\n";
	}
	return 0;

}