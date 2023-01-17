#include <iostream>
#include<vector>
#include <queue>




using namespace std;
int arr[501][501];

vector<pair<int, int>> xys (int n, int x, int y) {
	vector<pair<int, int>> v;
	if (n == 0) {
		v.push_back({ x,y });
		v.push_back({ x + 1,y });
		v.push_back({ x + 2,y });
		v.push_back({ x + 3,y });
	}
	else if (n == 1) {
		v.push_back({ x,y });
		v.push_back({ x + 1,y });
		v.push_back({ x + 1,y+1 });
		v.push_back({ x ,y+1 });
	}
	else if (n == 2) {
		v.push_back({ x,y });
		v.push_back({ x ,y+1 });
		v.push_back({ x ,y + 2 });
		v.push_back({ x+1 ,y + 2 });
	}
	else if (n == 3) {
		v.push_back({ x,y });
		v.push_back({ x ,y+1 });
		v.push_back({ x +1,y + 1 });
		v.push_back({ x+1 ,y + 2 });
	}
	else if(n==4){
		v.push_back({ x,y });
		v.push_back({ x + 1,y });
		v.push_back({ x + 1,y + 1 });
		v.push_back({ x+ 2,y });
	}
	else if (n == 5) {
		v.push_back({ x,y });
		v.push_back({ x ,y+1 });
		v.push_back({ x ,y + 2 });
		v.push_back({ x,y +3});
	}
	else if (n == 6) {
		v.push_back({ x,y });
		v.push_back({ x ,y + 1 });
		v.push_back({ x+1 ,y });
		v.push_back({ x+2,y });
	}
	else if (n == 7) {
		v.push_back({ x,y });
		v.push_back({ x+1 ,y + 1 });
		v.push_back({ x + 1 ,y });
		v.push_back({ x + 1,y+2 });
	}
	else if (n == 8) {
		v.push_back({ x,y });
		v.push_back({ x+1 ,y  });
		v.push_back({ x + 2 ,y });
		v.push_back({ x + 2,y-1 });
	}
	else if (n == 9) {
		v.push_back({ x,y });
		v.push_back({ x +1,y  });
		v.push_back({ x + 1 ,y-1 });
		v.push_back({ x + 2,y-1 });
	}
	else if (n == 10) {
		v.push_back({ x,y });
		v.push_back({ x ,y + 1 });
		v.push_back({ x + 1 ,y+1 });
		v.push_back({ x ,y+2 });
	}
	else if (n == 11) {
		v.push_back({ x,y });
		v.push_back({ x+1 ,y });
		v.push_back({ x + 1 ,y-1 });
		v.push_back({ x + 2,y });
	}
	else if (n == 12) {
		v.push_back({ x,y });
		v.push_back({ x+1 ,y });
		v.push_back({ x + 1 ,y-1 });
		v.push_back({ x + 1,y+1 });
	}
	else if (n == 13) {
		v.push_back({ x,y });
		v.push_back({ x + 1 ,y });
		v.push_back({ x + 1 ,y - 1 });
		v.push_back({ x + 1,y -2 });
	}
	else if (n == 14) {
		v.push_back({ x,y });
		v.push_back({ x  ,y+1 });
		v.push_back({ x + 1 ,y + 1 });
		v.push_back({ x +2,y + 1 });
	}
	else if (n == 15) {
		v.push_back({ x,y });
		v.push_back({ x + 1 ,y });
		v.push_back({ x ,y + 1 });
		v.push_back({ x ,y + 2 });
	}
	else if (n == 16) {
		v.push_back({ x,y });
		v.push_back({ x + 1 ,y });
		v.push_back({ x + 2 ,y  });
		v.push_back({ x + 2,y + 1 });
	}
	else if (n == 17) {
		v.push_back({ x,y });
		v.push_back({ x  ,y+1 });
		v.push_back({ x -1 ,y + 1 });
		v.push_back({ x - 1,y + 2 });
	}
	else if (n == 18) {
		v.push_back({ x,y });
		v.push_back({ x + 1 ,y });
		v.push_back({ x + 1 ,y + 1 });
		v.push_back({ x + 2,y + 1 });
	}
	return v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			int t;
			cin >> t;
			arr[i][j]=t;
		} 
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				vector<pair<int, int>> v;
				v = xys(k, i, j);
				int sum = 0;
				for (int l = 0; l < v.size(); l++) {
					
					if (v[l].first >= 0 && v[l].first < n && v[l].second >= 0 && v[l].second < m) {
						sum += arr[v[l].first][v[l].second];
					}
				}
				if (sum > max)
					max = sum;
			}
		}
	}
	cout<<max;

	
	
	return 0;
}