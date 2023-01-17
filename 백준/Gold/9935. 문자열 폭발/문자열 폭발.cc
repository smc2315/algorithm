#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	string bomb;
	cin >> bomb;
	int bombsize = bomb.size();

	string stk(1000000,NULL);
	int index = -1;
	for (int i = 0; i < s.size(); i++) {
		stk[++index] = s[i];
		
	
		if (bomb[bombsize - 1] == stk[index] && index >= bombsize - 1) {
			//cout << stk.substr(index - bombsize + 1, bombsize) << endl;
			if (stk.substr(index - bombsize+1, bombsize) == bomb) {
				
				index -= bombsize;
			}
		}

		
	}
	
	if (index==-1) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i <= index; i++) {
			cout << stk[i];
		}
	}

	return 0;
}