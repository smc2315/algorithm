#include <iostream>
#include<cmath>
#include <queue>


using namespace std;
struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) {
			return true;
		}
		else if (abs(n1) == abs(n2)) {
			return n1 > n2;
		}
			return false;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int,vector<int>,cmp> q;
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		if (m == 0) {
			if(q.empty()){
				cout << "0" << endl;
			}
			else {
				cout << q.top() << endl;
				q.pop();
			}
			
		}
		else {
			q.push(m);
		}
	}

	


	return 0;
}