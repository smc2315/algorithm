#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<long long, long long> m;

long long find_place(long long n){
    if(m[n]== 0){
        return n;
    }
    
    long long nn = find_place(m[n]);
    m[n] = nn;
    return nn;
    
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(auto i : room_number){
        long long room = find_place(i);
        answer.push_back(room);
        m[room] = room+1;
        
    }
    
    return answer;
}
