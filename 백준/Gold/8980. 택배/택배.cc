#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C; 
int M; 
vector<pair<pair<int, int>, int>> list; 
int truck[2001]; 
int success; 

bool compare(pair<pair<int, int>, int> a ,pair<pair<int, int>, int> b) { 
	if (a.first.second == b.first.second) return a.first.first < b.first.first;
	else return a.first.second < b.first.second;
}

int main() {
	cin >> N >> C;
	cin >> M;

	for (int i = 0; i < M; i++){
		int sender, receiver, box;
		cin >> sender >> receiver >> box;
		list.push_back({ {sender,receiver},box });
	}
	sort(list.begin(), list.end(),compare);

	for (int i = 0; i < list.size(); i++){
		int from = list[i].first.first; 
		int to = list[i].first.second; 
		int size = list[i].second; 
		int max_truck= 0;
		for (int j = from; j < to; j++){
			max_truck = max(truck[j], max_truck);
		}
		int capacity = min(size,C-max_truck);
		for (int j = from; j < to; j++) { 
			truck[j] += capacity;
		}
		success += capacity; 
	}
	cout << success;
}