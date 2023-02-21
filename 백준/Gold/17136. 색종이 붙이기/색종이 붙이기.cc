#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10
using namespace std;
int min_ans = 1e9;
int paper_cnt[5];
int board[MAX][MAX];

void input() {
	for (int i = 0; i < MAX; i++) 
		for (int j = 0; j < MAX; j++) 
			cin >> board[i][j];
}
bool can_attach_paper(int x, int y, int size){
	register int i, j;
	for (i = 0; i < size; ++i){
		for (j = 0; j < size; ++j)
			if (!board[x + i][y + j])
				return false;
	}
	return true;
}

void update_paper(int x, int y, int size, bool is_attach){
	register int i, j;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			board[x + i][y + j] = is_attach;
}

void dfs(int x, int y, int attach_cnt){
	while (board[x][y] == 0){
		if (++y >= MAX){
			if (++x >= MAX){
				min_ans = min(min_ans, attach_cnt);
				return;
			}
			y = 0;
		}
	}
	if (min_ans <= attach_cnt)
		return;

	for (int s = 5; s > 0; --s){
		if (x + s > MAX || y + s > MAX || paper_cnt[s] == 5) continue;

		if (can_attach_paper(x, y, s)){
			
			update_paper(x, y, s, 0);
			++paper_cnt[s];
			dfs(x, y, attach_cnt + 1);
			update_paper(x, y, s, 1);
			--paper_cnt[s];
		}
	}
}
void output() {
	if (min_ans == 1e9) {
		cout << -1;
		return;
	}
	cout << min_ans;
}
void solve() {
	input();
	dfs(0,0,0);
	output();
	
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();

	return 0;
}