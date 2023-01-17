#include <iostream>
#include<vector>
#include <queue>


using namespace std;
bool visited1[100][100];
bool visited2[100][100];
string srr[100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool visitedAll1(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (visited1[i][j] == false)
				return false;
		}
	}
	return true;
}
bool visitedAll2(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (visited2[i][j] == false)
				return false;
		}
	}
	return true;
}
void printVisited() {
	cout << "v1";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			cout << visited1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "v2";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			cout << visited2[i][j] << " ";
		}
		cout << endl;
	}
}
pair<int, int> findNewNode(int num,int num2) {
	if (num == 1) {
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				if (visited1[i][j] == false) {
					visited1[i][j] = true;
					//cout << i << " " << j << endl;
					return { i,j };
				}
			}
		}
	}
	else if (num == 2) {
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				if (visited2[i][j] == false) {
					visited2[i][j] = true;
					//cout << i << " " << j << endl;

					return { i,j };
				}
			}
		}
	}
}
void bfs(int num) {
	int result1 =0;
	int result2 = 0;
	queue<pair<int,int>> q1;
	queue<pair<int, int>> q2;
	q1.push({ 0,0 });
	q2.push({ 0,0 });
	visited1[0][0] = true;
	visited2[0][0] = true;
	bool finish1 = false;
	bool finish2 = false;
	while (true) {
		if (finish1 && finish2)
			break;
		//printVisited();
		if (q1.empty()&&!finish1) {
			q1.push(findNewNode(1, num));
			
		}

		if (q2.empty()&&!finish2) {
			q2.push(findNewNode(2, num));
		}
		
		while (!q1.empty()) {

			pair<int, int> cur = q1.front();
			//cout << q1.front().first << " " << q1.front().second << endl;
			q1.pop();
			
			for (int i = 0; i < 4; i++) {
				int ddx = cur.first + dx[i];
				int ddy = cur.second + dy[i];
				if (ddx >= 0 && ddy >= 0 && ddx < num && ddy < num) {
					if (!visited1[ddx][ddy]) {
						if (srr[cur.first][cur.second] == srr[ddx][ddy]) {
							q1.push({ ddx,ddy });
							visited1[ddx][ddy] = true;
						}
					}

				}

			}

		}
		if (!finish1) {
			result1++;
		}
		while (!q2.empty()) {

			pair<int, int> cur = q2.front();

			q2.pop();

			for (int i = 0; i < 4; i++) {
				int ddx = cur.first + dx[i];
				int ddy = cur.second + dy[i];
				if (ddx >= 0 && ddy >= 0 && ddx < num && ddy < num) {
					if (!visited2[ddx][ddy]) {
						if (srr[cur.first][cur.second] == 'R' || srr[cur.first][cur.second] == 'G') {
							if (srr[ddx][ddy] == 'R' || srr[ddx][ddy] == 'G') {
								q2.push({ ddx,ddy });
								visited2[ddx][ddy] = true;
							}
						}
						else if(srr[cur.first][cur.second] == 'B'){
							if (srr[ddx][ddy] == srr[cur.first][cur.second]) {
								q2.push({ ddx,ddy });
								visited2[ddx][ddy] = true;
							}
						}
					}

				}

			}

		}
		if (!finish2) {
			result2++;
		}
		finish1 = visitedAll1(num);
		finish2 = visitedAll2(num);
	}

	cout << result1 <<" "<< result2;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		srr[i] = s;
		
	}
	bfs(n);


	return 0;
}