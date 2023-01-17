#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> name;
vector<string> name2;
vector<string> name3;

void find(string what,int s, int e)
{
	int start = s;
	int end = e;
	int mid = (start + end) / 2;
	if (start >= end)
		return;
	if (name[mid] == what)
	{
		name3.push_back(what);
		return;
	}
	
	if (name[mid] < what)
	{
		find(what, mid+1, e);
	}
	else
	{
		find(what, s, mid);
	}



}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		name.push_back(s);

	}
	sort(name.begin(), name.end());
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >>s;
		name2.push_back(s);

	}
	sort(name2.begin(), name2.end());
	for (int i = 0; i < name2.size(); i++)
	{
		find(name2[i], 0, name2.size());
	}
	cout << name3.size() << "\n";
	for (int i = 0; i < name3.size(); i++)
	{
		cout << name3[i]<<"\n";
	}
	return 0;
}