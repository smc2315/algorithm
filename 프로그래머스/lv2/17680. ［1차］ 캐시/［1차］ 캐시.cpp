#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(),
            [](unsigned char c){ return tolower(c); });
    }
    int answer = 0;
    int size = 0;
    deque<string> q;
    
    if(cities.empty())
        return 0;
    if(cacheSize==0){
        return cities.size()*5;
    }
    q.push_back(cities[0]);

    answer+=5;
    for(int i=1;i<cities.size();i++){
        auto iter = find(q.begin(),q.end(),cities[i]);
        if(iter!=q.end()){
            q.erase(iter);
            q.push_back(cities[i]);
            answer++;
        }
        else{
            if(q.size()<cacheSize){
                q.push_back(cities[i]);
                answer+=5;
            }
            else{
                q.pop_front();
                q.push_back(cities[i]);
                answer+=5;
            }
        }
        
    }
    
    
    return answer;
}