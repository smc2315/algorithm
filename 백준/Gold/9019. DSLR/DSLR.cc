#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
bool visited[10000] = { false, };


void BFS(int a, int b) {
	queue<pair<int,string>> q;
	q.push({ a,""});
	visited[a] = true;
	while (!q.empty()) {
		int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }

        int D, S, L, R, temp;
        // D 연산
        D = (cur_num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = true;
            q.push(make_pair(D, cur_op + "D"));
        }

        // S 연산
        S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!visited[S])
        {
            visited[S] = true;
            q.push(make_pair(S, cur_op + "S"));
        }

        // L 연산
        L = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(make_pair(L, cur_op + "L"));
        }

        // R 연산
        R = cur_num / 10 + (cur_num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = true;
            q.push(make_pair(R, cur_op + "R"));
        }

	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int A, B;
		cin >> A >> B;
		
		BFS(A, B);
        memset(visited, false, sizeof(visited));

	}
    return 0;


}