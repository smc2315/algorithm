#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int ans = 0;
int graph[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void dragonCurve(int g,vector<pair<int,int>> v) {
	
	if (g == 0) {
		return;
	}
	int pointX = v[v.size() - 1].first;
	int pointY = v[v.size() - 1].second;
	for (int i = v.size()-2; i >=0; i--) {
		int nextX = pointX - (pointY - v[i].second);
		int nextY = pointY + (pointX - v[i].first);
		v.push_back({ nextX,nextY });
		graph[nextX][nextY] = 1;
		
	}
	dragonCurve(g - 1, v);

}

void countSquare() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (graph[i][j] == 1 && graph[i + 1][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j + 1] == 1) {
				ans++;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		vector<pair<int, int>> v;
		cin >> x >> y >> d >> g;
		graph[y][x] = 1;
		graph[y + dx[d]][x + dy[d]] = 1;
		v.push_back({ y,x });
		v.push_back({ y + dx[d],x + dy[d] });
		dragonCurve( g,v);
	}
	

	countSquare();
	cout << ans;
	return 0;
}