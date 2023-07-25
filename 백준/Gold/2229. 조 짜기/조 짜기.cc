#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> students;
int dp[1001];
int N;


int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        int tmp;
        cin>>tmp;
        students.push_back(tmp);
    }

    dp[1] = abs(students[1]-students[0]);

    for(int i=2;i<N;i++){
        int mmin = students[i];
        int mmax = students[i];
        for(int j=i;j>0;j--){
            mmin = min(mmin, students[j]);
            mmax = max(mmax, students[j]);
        
            dp[i] = max(dp[i], dp[j-1]+mmax-mmin);
        }
    }
    cout<<dp[N-1];
}