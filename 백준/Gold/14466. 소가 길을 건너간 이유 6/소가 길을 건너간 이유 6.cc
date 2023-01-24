#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
set<p> g[111][111];
int n, k, r;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int visited[111][111];

void dfs(int i, int j){
	if(i < 1 || i > n || j < 1 || j > n) return;
	visited[i][j] = 1;
	for(int x=0; x<4; x++){
		int ii = i + di[x];
		int jj = j + dj[x];
		if(!visited[ii][jj] && !g[i][j].count({ii, jj})){
			dfs(ii, jj);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> r;

	for(int i=0; i<r; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		g[a][b].insert({c, d});
		g[c][d].insert({a, b});
	}

	vector<p> v(k);
	for(int i=0; i<k; i++){
		cin >> v[i].first >> v[i].second;
	}

	int ans = 0;
	for(int i=0; i<k; i++){
		memset(visited, 0, sizeof visited);
		dfs(v[i].first, v[i].second);
		for(int j=i+1; j<k; j++){
			if(!visited[v[j].first][v[j].second]){
				ans++;
			}
		}
	}
	cout << ans;
}