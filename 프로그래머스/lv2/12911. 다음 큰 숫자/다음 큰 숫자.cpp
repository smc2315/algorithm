#include <string>
#include <vector>

using namespace std;

int count_one(int n){
    int cnt=0;
    while(n>0){
        if(n%2==1)
            cnt++;
        n/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = count_one(n);
    while(true){
        if(count_one(++n)==cnt)
            break;
    }
    return n;
}