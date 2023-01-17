#include <iostream>
#include<vector>
#include <queue>



using namespace std;
bool bitmask[21] = { false, };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		string s;
		int m;
		cin >> s;
		if (s == "add") {
			cin >> m;
			bitmask[m] = true;
		}
		else if (s == "remove") {
			cin >> m;
			bitmask[m] = false;
		}
		else if (s == "check") {
			cin >> m;
			if (bitmask[m]) {
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> m;
			bitmask[m]=!bitmask[m];
		}
		else if (s == "all") {
			fill_n(bitmask,21, true);
		}
		else if (s == "empty") {
			fill_n(bitmask, 21, false);
		}
	}
	
	return 0;
}