#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int graph[201][201];
vector<int> plan;

bool dfs(int s,int d) {
	vector<bool> visited;
	for (int i = 0; i < N; i++) {
		visited.push_back(false);
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == d) {
			return true;
		}
		for (int i = 0; i < N; i++) {
			if (graph[cur][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return false;


}

void go() {
	for (int i = 0; i < plan.size()-1; i++) {
		if (!dfs(plan[i] - 1, plan[i + 1] - 1)) {
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
	exit(0);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			graph[i][j] = tmp;
		}
	}
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		plan.push_back(tmp);
	}

	go();

}