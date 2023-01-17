#include <iostream>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int selected[13];
int result = 1e9;

void setChicken(int num) {
	if (num == m) {
		int sum=0;
		for (int i = 0; i < house.size(); i++) {
			
			
			int mmin = 1e9;
			for (int j = 0; j < m; j++) {
				int dist;
				dist = abs(house[i].first - chicken[selected[j]].first) + abs(house[i].second - chicken[selected[j]].second);
				if (dist < mmin) {
					mmin = dist;
				}
			}
			
			sum+=mmin;
			
		}
		if (result > sum)
				result = sum;
		return;
	}
	
		for (int i = 0; i < chicken.size(); i++) {
			if (num==0||i > selected[num - 1]) {
				selected[num] = i;
				setChicken(num + 1);
				selected[num] = 0;
			}
		}
	
	
	

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == 2) {
				chicken.push_back({ i,j });
			}
			else if (t == 1) {
				house.push_back({ i,j });
			}
		}
	}
	
	setChicken(0);
	cout << result;
	

	return 0;
}