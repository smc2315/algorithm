#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;


int solution(vector<int> stones, int k) {
    multiset<int> s;
    int mmin = 1e9;
    for(int i=0;i<k-1;i++){
        s.insert(stones[i]);
    }
    for(int i= k-1;i<stones.size();i++){
        s.insert(stones[i]);
        auto it = s.end();
        --it;
        mmin = min(mmin,*it);
        s.erase(s.find(stones[i-(k-1)]));
    }
    return mmin;
}