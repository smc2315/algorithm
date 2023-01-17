#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int start = 0;
    int end = 1;
    while(end<n){
        int sum=0;
        sum = end*(end+1)/2 - (start-1)*(start)/2;
        
        if(sum == n){
            
            answer++;
            start++;
            end++;
        }
        else if(sum>n){
            start++;
        }
        else{
            end++;
        }
            
    }
    return answer+1;
}