#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
using namespace std;

vector<deque<int>> v(4);

void getCurState(int n,int state[]) {
	
	state[0] = v[0][2] != v[1][6];
	state[1] = v[1][2] != v[2][6];
	state[2] = v[2][2] != v[3][6];
	
	
}
void rotate(int n, int d) {
	bool doneLeft = false;
	bool doneRight = false;
	int left = n;
	int right = n;
	int	leftD = d;
	int rightD = d;
	int state[3];
	getCurState(n,state);
	

	if (d == -1) {
		int tmp = v[n].front();
		v[n].pop_front();
		v[n].push_back(tmp);

	}
	else {
		int tmp = v[n].back();
		v[n].pop_back();
		v[n].push_front(tmp);
	}

	
	while (!doneLeft||!doneRight) {
		left =left - 1;
		right = right + 1;
		if (left < 0||doneLeft==true) {
			doneLeft = true;
		}
		else {
			
			if (state[left]) {

				if (leftD == 1) {
					int tmp = v[left][0];
					v[left].pop_front();
					v[left].push_back(tmp);
					leftD = -1;
				}
				else {
					int tmp = v[left][7];
					v[left].pop_back();
					v[left].push_front(tmp);
					leftD = 1;
				}


			}
			else
				doneLeft = true;
		}
		if (right >= 4||doneRight==true) {
			doneRight = true;
		}
		else {
			if (state[right-1]) {
				if (rightD == 1) {
					int tmp = v[right][0];
					v[right].pop_front();
					v[right].push_back(tmp);
					rightD = -1;
				}
				else {
					int tmp = v[right][7];
					v[right].pop_back();
					v[right].push_front(tmp);
					rightD = 1;
				}

			}
			else
				doneRight = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++) {
		
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			v[i].push_back(tmp[j]-'0');
		}
		
	}
	
	int k;
	cin >> k;
	while (k--) {
		int n, d;
		cin >> n >> d;
		rotate(n-1, d);
	}
	
	cout << v[0][0] * 1 + v[1][0] * 2 + v[2][0] * 4 + v[3][0] * 8<<endl;
	return 0;
}