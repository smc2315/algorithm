#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
long long n,b,c,ans;
int v[1000100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >>b>>c;
	for (int i = 0; i < n ; i++) {
		cin >> v[i];
	}
    if(b<=c){
        for(int i=0;i<n;i++){
            ans+=b*v[i];
        }
        cout<<ans<<endl;
        return 0;
    }
	for (int i = 0; i < n; i++) {
		if (v[i + 1] > v[i + 2]) {
			int two = min(v[i], v[i + 1] - v[i + 2]);
			ans += (b+c) * two;
			v[i] -= two;
			v[i + 1] -= two;

			int three = min(v[i], min(v[i + 1], v[i + 2]));
			ans += (b+2*c) * three;
			v[i] -= three;
			v[i + 1] -= three;
			v[i + 2] -= three;
		}
		else {
			int three = min(v[i], min(v[i + 1], v[i + 2]));
			ans += (b+2*c) * three;
			v[i] -= three;
			v[i + 1] -= three;
			v[i + 2] -= three;

			int two = min(v[i], v[i + 1]);
			ans += (b+c) * two;
			v[i] -= two;
			v[i + 1] -= two;
		
		}
		ans += b * v[i];
	}
	cout << ans<<endl;
	return 0;
}