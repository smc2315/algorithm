#include <iostream>
#include<vector>
#include <stack>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> stk;
	int n, k;
	cin >> n >> k;
	while (n--) {
		int num;
		cin >> num;
		stk.push(num);
	}
	int result=0;
	while (!stk.empty()) {
		if (k == 0)
			break;
		int cur;
		cur = stk.top();
		stk.pop();
		while (k - cur >= 0) {
			//cout << k << endl;
			k -= cur;
			result++;
		}
	}
	cout << result;


	return 0;
}