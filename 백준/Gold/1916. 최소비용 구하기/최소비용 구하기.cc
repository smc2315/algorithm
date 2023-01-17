#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1e9


using namespace std;
int n, m;

vector<pair<int, int>> v[1001];
int dist[1001];
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			if  (dist[v[cur][i].first] > cost + v[cur][i].second) {
				dist[v[cur][i].first] = cost + v[cur][i].second;
				pq.push({ -(cost + v[cur][i].second),v[cur][i].first });
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dist, dist + 1001, INF);
	
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		
	}
	int s, e;
	cin >> s >> e;
	dijkstra(s);
	cout << dist[e];
	
	return 0;
}