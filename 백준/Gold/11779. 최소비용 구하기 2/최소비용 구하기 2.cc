#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;
int n;
vector<pair<int, int>> v[1001];
int  dist[1001];
int from[1001];

void dijkstra(int s, int e) {

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	dist[s]= 0 ;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost)
			continue;
			
		for (int i = 0; i < v[cur].size(); i++) {
			if (dist[v[cur][i].first] > cost + v[cur][i].second) {
				dist[v[cur][i].first] = cost + v[cur][i].second;
				from[v[cur][i].first] = cur;
				pq.push({ -(cost + v[cur][i].second),v[cur][i].first });

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int m;
	cin >> n >> m;
	fill(dist, dist + n+1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		
	}
	int s, e;
	cin >> s >> e;
	dijkstra(s, e);
	cout << dist[e] << "\n";
	vector<int> result;
	int tmp = e;

	while (tmp) {
		result.push_back(tmp);
		tmp = from[tmp];
	
	}
	cout << result.size() << endl;
	for (int i = result.size()-1; i >=0; i--) {
		cout << result[i] << " ";
	}
	return 0;

}