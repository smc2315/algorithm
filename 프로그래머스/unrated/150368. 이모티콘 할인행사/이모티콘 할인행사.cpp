#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mmax = 0;
int mmax2 = 0;

void dfs(vector<vector<int>> user,vector<int> emo, vector<int> v,int n,int cnt) {
    if(n==cnt){
        int plus = 0;
        int ssum = 0;
        for(int i=0;i<user.size();i++){
            int dis = user[i][0];
            int amount = user[i][1];
            int sum = 0;
            bool flag = false;
            for(int j=0;j<n;j++){
                //cout<<v[j]<<endl;
                int tmp = emo[j] / 100 * (100-v[j]);
                if(v[j]>=dis) {
                    sum+=tmp;
                }
                if(sum>=amount){
                    plus++;
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                ssum += sum;
            }
        }
        
        if(mmax < plus){
            mmax = plus;
            mmax2 = ssum;
        }
        else if(mmax == plus){
            if(mmax2 < ssum){
                mmax2 = ssum;
            }
        }
        
        return;
    }
    
    for(int j=1;j<=4;j++){
        v[cnt]=j*10;
        dfs(user,emo,v,n,cnt+1);
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> v(7);
    dfs(users, emoticons,v, emoticons.size(), 0);
    answer.push_back(mmax);
    answer.push_back(mmax2);
    return answer;
}