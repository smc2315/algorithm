#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct student {
	int age;
	int i;
	string name;
};
bool compare(student a, student b) 
{
	if (a.age == b.age) 
	{   
		return a.i < b.i;
	}
	else 
	{                  
		return a.age < b.age;
	}

}
int main()
{
	int n;
	cin >> n;
	vector<student> v;
	for (int i = 0; i < n; i++)
	{
		student s;
		cin >> s.age >> s.name;
		s.i = i;
		v.push_back(s);

	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].age << " " << v[i].name << "\n";
	return 0;
}