#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<stack>


using namespace std;

vector<vector<pair<int,int>>> tree(100000);
int n;
bool visited[100000];
int maxnode;
int mmax = 0;
void dfs(int i) {
	stack<pair<int, int>> stk;
	
	
		
	stk.push({ i,0 });
	visited[i] = true;
	while (!stk.empty()) {

		int cur = stk.top().first;
		int len = stk.top().second;
		if (len > mmax) {
			mmax = len;
			maxnode = cur;
		}
		stk.pop();
		for (int j = 0; j < int(tree[cur].size()); j++) {
			if (!visited[tree[cur][j].first]) {
				stk.push({ tree[cur][j].first,tree[cur][j].second+len });
				visited[tree[cur][j].first] = true;
			}
		}
		//cout << cur+1 << endl;
	}
	
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		int k;
		int cnt=1;
		int tmp=-1;
		while (cin >> k) {
			if (k == -1)
				break;
			if (cnt % 2 == 1) {
				tmp = k;
			}
			else {
				tree[v - 1].push_back({ tmp - 1,k });
			}
			cnt++;
		}
	}
	dfs(1);
	memset(visited, false,sizeof(visited));
	mmax = 0;
	dfs(maxnode);
	cout << mmax;
    return 0;
}
