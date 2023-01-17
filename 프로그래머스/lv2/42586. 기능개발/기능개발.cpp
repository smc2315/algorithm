#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cur=0;
    while(cur<speeds.size()){
        for(int i=cur;i<speeds.size();i++){
            progresses[i]+=speeds[i];
        }
        int ans=0;
        while(progresses[cur]>=100){
            ans++;
            cur++;
            if(cur>=speeds.size())
                break;
        }
        if(ans!=0){
            answer.push_back(ans);
        }
    }
    return answer;
}