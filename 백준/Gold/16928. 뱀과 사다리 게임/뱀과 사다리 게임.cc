#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

int arr[101];
bool visited[101];
int n, m;
void bfs() {

	queue<pair<int,int>> q;
	q.push({ 1,0 });
	visited[1] = true;
	
	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		if (cur == 100) {
			cout << cnt;
			break;
		}
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (!visited[next]&&next<=100) {
				q.push({ arr[next],cnt + 1 });
				visited[next] = true;
				visited[arr[next]] = true;
			}
		}
		
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> n>>m;
	for (int i = 0; i < 101; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int l1,l2;
		cin >> l1>>l2;
		arr[l1] = l2;
	}
	for (int i = 0; i < m; i++) {
		int s1, s2;
		cin >> s1 >> s2;
		arr[s1] = s2;
	}
	bfs();
	
	return 0;


}