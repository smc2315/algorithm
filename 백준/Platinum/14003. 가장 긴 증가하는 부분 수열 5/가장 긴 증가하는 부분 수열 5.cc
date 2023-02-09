#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
vector<int> arr;
int index[1000001];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
}

int find_index(int n) {
	int start = 0;
	int end = arr.size()-1;
	while (start < end){
		int mid = (start + end) / 2;

		if (arr[mid] >= n) end = mid;
		else start = mid + 1;
	}
	return start;

}

void solution() {
	arr.push_back(v[0]);
	for(int i = 1; i < N; i++) {
		if (v[i] > arr[arr.size() - 1]) {
			arr.push_back(v[i]);
			index[i] = arr.size() - 1;
		}
		else {
			int idx = find_index(v[i]);
			arr[idx] = v[i];
			index[i] = idx;
		}
	}
	
	cout << arr.size() << endl;
	vector<int> Answer;
	int find_Index = arr.size() - 1;
	for (int i = N-1; i >= 0; i--)
	{
		if (index[i] == find_Index)
		{
			find_Index--;
			Answer.push_back(v[i]);
		}
	}
	for (int i = Answer.size() - 1; i >= 0; i--) cout << Answer[i] << " ";
	cout << endl;
	
}

void solve() {
	input();
	solution();
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();

	return 0;
}