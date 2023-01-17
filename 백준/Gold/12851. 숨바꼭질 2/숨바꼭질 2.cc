#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
bool visited[100001];
int result = 10000000;
int resultcnt = 0;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ n,0 });
	visited[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[cur] = true;
		//cout << cnt << " "<<cur<<" "<<result<<endl;

		if (cur == m && result >= cnt) {
			result = cnt;

		}
		if (cur == m && result == cnt) {
			resultcnt++;
		}
		if (cnt >= result)
			continue;
		visited[m] = false;
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1,cnt + 1 });

		
		}
		if (cur + 1 <= 100000 && !visited[cur + 1]) {
			q.push({ cur + 1,cnt + 1 });
			
		}
		if (cur * 2 <= 100000 && !visited[cur * 2]) {

			q.push({ cur * 2,cnt + 1 });
			
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	bfs();
	cout << result << endl << resultcnt;
	return 0;
}