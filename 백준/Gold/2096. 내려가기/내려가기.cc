#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dp1[3];
	int dp2[3];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0) {
			dp1[0] = a;
			dp1[1] = b;
			dp1[2] = c;

			dp2[0] = a;
			dp2[1] = b;
			dp2[2] = c;
		}
		else {
			int tmp1, tmp2, tmp3;

			tmp1 = max(dp1[0] + a, dp1[1] + a);
			tmp2 = max(dp1[0] + b, max(dp1[1] + b, dp1[2] + b));
			tmp3 = max(dp1[1] + c, dp1[2] + c);

			dp1[0] = tmp1;
			dp1[1] = tmp2;
			dp1[2] = tmp3;

			tmp1 = min(dp2[0] + a, dp2[1] + a);
			tmp2 = min(dp2[0] + b, min(dp2[1] + b, dp2[2] + b));
			tmp3 = min(dp2[1] + c, dp2[2] + c);

			dp2[0] = tmp1;
			dp2[1] = tmp2;
			dp2[2] = tmp3;
		}
	}
	cout << max(dp1[0], max(dp1[1], dp1[2])) << "\n" << min(dp2[0], min(dp2[1], dp2[2]));


	
	
	return 0;
}