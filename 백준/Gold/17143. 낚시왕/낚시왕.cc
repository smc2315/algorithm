#include <iostream>
#include <vector>
using namespace std;

const int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
struct Shark {
	int r, c, s, d, z;

};
int R, C, M;	
int Answer;
vector<Shark> Sharks[102][102];	

bool in_range(int r, int c) {
	return 0 < r && r <= R && 0 < c && c <= C;
}

int change_dir(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}

int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= ((R - 1) * 2);	
		if (d == 3 || d == 4) s %= ((C - 1) * 2);	
		Sharks[r][c].push_back({ r, c, s, d, z });
	}
	int K = 0;
	while (++K <= C) {
	
		for (int i = 1; i <= R; i++) {
			if (!Sharks[i][K].empty()) {
				Answer += Sharks[i][K][0].z;
				Sharks[i][K].pop_back();
				break;
			}
		}
		vector<Shark> newSharks[102][102];
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (Sharks[i][j].empty()) continue;
				Shark currShark = Sharks[i][j][0];
				Sharks[i][j].pop_back();

				int& cr = currShark.r;
				int& cc = currShark.c;
				int cs = currShark.s;
				int& cd = currShark.d;

				while (cs--) {
					int nr = cr + dir[cd][0];
					int nc = cc + dir[cd][1];
					if (!in_range(nr, nc)) {
						cd = change_dir(cd);
					}
					cr += dir[cd][0];
					cc += dir[cd][1];
				}
			
				if (!newSharks[cr][cc].empty()) {
					if (newSharks[cr][cc][0].z < currShark.z) {
						newSharks[cr][cc].pop_back();
						newSharks[cr][cc].push_back(currShark);
					}
				}
				
				else newSharks[cr][cc].push_back(currShark);
			}
		}
	
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				Sharks[i][j] = newSharks[i][j];
			}
		}
	}
	cout << Answer << endl;
	return 0;
}