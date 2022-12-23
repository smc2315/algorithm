#include <string>
#include <vector>
#include <set>

using namespace std;


set<string> ss;

bool compareId(string user_id, string banned_id){
    for(int i=0;i<user_id.size();i++){
        if(banned_id[i] == '*')
            continue;
        if(user_id[i]!=banned_id[i]){
            return false;
        }
    }
    return true;
}
void backTracking(vector<string> user_id, vector<string> banned_id, int cnt,string s){
    if(banned_id.size() == cnt){
        ss.insert(s);
        return;
    }
    
    for(int i=0;i<user_id.size();i++){
        if(s[i]=='0'&&banned_id[cnt].size() == user_id[i].size()){
            if(compareId(user_id[i],banned_id[cnt])){
                
                s[i] = '1';
                backTracking(user_id,banned_id,cnt+1,s);
                s[i] = '0';
            }
        }
    }
        
}

int solution(vector<string> user_id, vector<string> banned_id) {
    string s="";
    for(int i=0;i<user_id.size();i++)
        s+='0';
        
    backTracking(user_id,banned_id,0,s);
    return ss.size();
}
