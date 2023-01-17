#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return (a < b);
	return a.length() < b.length();

}

int main()
{
	int num;
	vector<string> v;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
	
		v.push_back(s);
	}
	sort(v.begin(),v.end(),compare);
	cout << v[0] << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if(i>0)
			if(v[i-1] != v[i])
				cout << v[i] << endl;
	}
	return 0;
}