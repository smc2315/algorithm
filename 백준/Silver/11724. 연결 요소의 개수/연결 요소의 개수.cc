#include <iostream>
#include<vector>
#include <queue>



using namespace std;
bool visited[1001] = { false, };
int n, m;
vector<pair<int, int>> vp;

int checkVisit() {
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false)
			return i;
	}
	return -1;
}
void bfs() {
	int cnt = 0;

	while (checkVisit()!=-1) {
		queue<int> q;
		int next = checkVisit();
		//cout << next << "\n";
		q.push(next);
		visited[next] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < vp.size(); i++) {
				if (vp[i].first == cur && !visited[vp[i].second]) {
					q.push(vp[i].second);
					visited[vp[i].second] = true;
					//cout << vp[i].second<<" "<<cnt<<endl;
				}
				else if (vp[i].second == cur && !visited[vp[i].first]) {
					q.push(vp[i].first);
					visited[vp[i].first] = true;
					//cout << vp[i].first << " " << cnt << endl;
				}
			}
		}
		//cout << "\n";
		cnt++;
	}
	cout << cnt;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		vp.push_back({ u,v });
	}
	bfs();
	
	return 0;
}