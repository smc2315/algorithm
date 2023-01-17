#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<string>> v(101, vector<string>(101));

string ssum(string s1, string s2) {
    int sum = 0;
    string result;

    
    while (!s1.empty() || !s2.empty() || sum)
    {
        if (!s1.empty())
        {
            sum += s1.back() - '0';
            s1.pop_back();
        }
        if (!s2.empty())
        {
            sum += s2.back() - '0';
            s2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    
    reverse(result.begin(), result.end());
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <=i; j++) {
            if (j == 0||j==i) {
                v[i][j] = "1";
            }
            else
                v[i][j] = ssum(v[i - 1][j - 1], v[i - 1][j]);
           
        }
    }
    
    cout <<v[n][m];

    return 0;

   
}