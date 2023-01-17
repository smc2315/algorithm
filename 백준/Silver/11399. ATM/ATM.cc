#include <iostream>
#include<cmath>
#include <queue>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int,vector<int>,greater<int>> q;
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		q.push(m);
	}
	int sum = 0;
	int num = q.size();
	while (!q.empty()) {
		sum+=num--*q.top();	
		q.pop();
	}
	cout << sum;
	

	return 0;
}