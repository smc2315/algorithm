#include <iostream>
#include<vector>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long arr[100] = { 1,1,1,2,2, };
	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	while (n--) {
		
		int m;
		cin >> m;
		
		cout << arr[m-1] << endl;
		
		
	}


	return 0;
}