#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, X, Y;
vector<pair<int, int>> arr[100001];
pair<int,int> dist[1001];

void dijkstra() {
	
	for (int i = 0; i < N; i++) {
		dist[i].first = 1e9;
	}
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,Y });
	dist[Y].first = 0;
	dist[Y].second = Y;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextcost = arr[cur][i].second;

			if (dist[next].first > dist[cur].first + nextcost) {
				dist[next].first = dist[cur].first + nextcost;
				dist[next].second = next;
				pq.push({ -dist[next].first, next });
			}
		}
	}
}

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> X >> Y;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	dijkstra();
	sort(dist, dist + N, comp);
	
	int cnt = 1;
	int day = X;

	for (int i = 0; i < N; i++) {

		int distance = dist[i].first * 2;
		if (distance > X) {
			cout << -1 << endl;
			return 0;
		}

		if (day < distance) {
			cnt++;
			i--;
			day = X;
			continue;
		}
		day -= distance;
	}

	cout << cnt << endl;
	return 0;
}