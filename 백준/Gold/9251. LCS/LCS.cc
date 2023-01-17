#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int LCS[1001][1001];

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	string s1, s2;
	cin >> s1 >> s2;


	
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
			}
			else {
				LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i+1][j]);
			}
		}
	}
	cout << LCS[s1.length()][s2.length()];
	return 0;
}