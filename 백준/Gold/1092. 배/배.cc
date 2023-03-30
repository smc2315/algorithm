#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N,M;
vector<int> arrN, arrM;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arrN.push_back(tmp);
	}
	sort(arrN.begin(), arrN.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		arrM.push_back(tmp);
	}
	sort(arrM.begin(), arrM.end());


	if (arrM[arrM.size()-1] > arrN[arrN.size() - 1]) {
		cout << -1;
		return 0;
	}
	int cnt = 0;
	int time = 0;
	while (cnt < M) {
		for (int i = N-1; i >= 0; i--) {
			for (int j = arrM.size()-1; j >= 0; j--) {
				
				if (arrN[i] >= arrM[j]) {
					cnt++;
					arrM.erase(arrM.begin() + j);
					break;
				}
			}
		}
		time++;
	}
	cout << time;

	
}