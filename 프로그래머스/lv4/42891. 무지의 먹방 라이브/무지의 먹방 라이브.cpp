#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    
    vector<pair<int,int>> foods;
    int food_size = food_times.size();
    for(int i = 0; i < food_size; i++){
        foods.push_back({food_times[i],i + 1});
    }
    
    sort(foods.begin(), foods.end());
    
    int prevTime = 0;
    for (auto it = foods.begin(); it != foods.end(); it++, food_size--){
        int gap = it->first - prevTime; 
        long long spendTime = (long long)gap * food_size; 
        if(gap == 0) continue;
        
        if(spendTime <= k){
            k -= spendTime; 
            prevTime = it->first; 
        }
        else{ 
            k %= food_size;
            sort(it, foods.end(), comp);
            return (it + k)->second; 
        }
    }
    
    return -1;
}