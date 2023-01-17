#include <iostream>
#include<vector>
#include <queue>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> q;
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		if (m == 0) {
			if(q.empty()){
				cout << "0" << "\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
			
		}
		else {
			q.push(m);
		}
	}

	


	return 0;
}