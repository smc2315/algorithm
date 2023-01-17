#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int arr[10]={0,};
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        arr[priorities[i]]++;
    }
    int cnt=0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        bool check = false;
        for(int i=cur.first+1;i<10;i++){
            if(arr[i]!=0){
                q.push(cur);
                check = true;
                break;
            }
        }
        if(!check){
            cnt++;
            arr[cur.first]--;
            if(cur.second == location){
                answer = cnt;
                break;
            }
        }
    }
    return answer;
}