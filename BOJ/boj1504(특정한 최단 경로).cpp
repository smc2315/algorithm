#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, E;
vector<pair<int, int>> v[801];
int N1, N2;
int dist[801];

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e8;
	}
	dist[s] = 0;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = -cur.first;
		int node = cur.second;

		for (int i = 0; i < v[node].size(); i++) {
			if (dist[v[node][i].first] > v[node][i].second + cost) {
				dist[v[node][i].first] = v[node][i].second + cost;
				pq.push({ -(v[node][i].second + cost),v[node][i].first });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> N1 >> N2;

	int case1 = 0; 
	int case2 = 0;
	dijkstra(1);
	case1 += dist[N1];
	case2 += dist[N2];

	dijkstra(N1);
	case1 += dist[N2];
	case2 += dist[N];
    

	dijkstra(N2);
	case2 += dist[N1];
	case1 += dist[N];
    


	if(case1>=1e8 && case2>=1e8){
        cout<<-1;
    }
    else
	    cout << min(case1, case2);
    
    return 0;

}
