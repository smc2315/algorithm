#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
long long m;
vector<vector<int>> arr(5,vector<int>(5));

vector<vector<int>> mul(vector<vector<int>> v1, vector<vector<int>> v2) {
	vector<vector<int>> result(n,vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long tmp=0;
			for (int k = 0; k < n; k++) {
				tmp += (v1[i][k] * v2[k][j])%1000;
			}
			result[i][j] = tmp%1000;
		}
	}
	return result;
}

vector<vector<int>> pow(vector<vector<int>> result) {
	while (m > 0) {
		if (m % 2 == 1) {
			result = mul(result, arr);
		}
		m /= 2;
		arr = mul(arr, arr);
	}
	return result;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;

			cin >> t;
			arr[i][j] = t%1000;
			
		}
	}
	vector<vector<int>> result(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		result[i][i] = 1;
	}
	result =pow(result);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}