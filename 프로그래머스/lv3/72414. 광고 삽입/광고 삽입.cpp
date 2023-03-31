#include <string>
#include <vector>

using namespace std;
int arr[360010];

int time_to_sec(string time){
    int ret=0;
    ret+=3600*stoi(time.substr(0,2));
    ret+=60*stoi(time.substr(3,2));
    ret+=stoi(time.substr(6,2));
    return ret;
}

string sec_to_time(int sec){
    string ret = "";
    int h = sec/3600;
    sec%=3600;
    int m = sec/60;
    int s = sec%60;
    
    ret += h >= 10 ? to_string(h) : ("0" + to_string(h));
    ret += ":";
    ret += m >= 10 ? to_string(m) : ("0" + to_string(m));
    ret += ":";
    ret += s >= 10 ? to_string(s) : ("0" + to_string(s));
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    int adv = time_to_sec(adv_time);
    int end = time_to_sec(play_time);
    for(auto log : logs){
        int a = time_to_sec(log.substr(0,8));
        int b = time_to_sec(log.substr(9));
        arr[a]++;
        arr[b]--;
    }
    for(int i=0;i<end-1;i++)
        arr[i+1] += arr[i]; 
    
    long long sum=0;
    for(int i=0;i<adv;i++)
        sum+=arr[i];
    
    long long mmax = sum;
    int answer = 0;
    for(int i=adv;i<end;i++){
        sum+=arr[i];
        sum-=arr[i-adv];
        if(sum>mmax){
            mmax = sum;
            answer = i-adv+1;
        }
        
    }
    return sec_to_time(answer);
}