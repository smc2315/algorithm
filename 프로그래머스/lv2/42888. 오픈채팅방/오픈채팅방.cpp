#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,vector<int>> m;
    unordered_map<string,string> m2;
    int index = 0;
    for(int i=0;i<record.size();i++){
        vector<string> words;
        stringstream sstream(record[i]);
        string word;
        
        while(getline(sstream, word, ' ')){
            words.push_back(word);
        }
        
        if(words[0] == "Enter"){
            if(m[words[1]].size() == 0){
                m[words[1]].push_back(index++);
                answer.push_back(words[2]+"님이 들어왔습니다.");
            }
            else{
                for(int j=0;j<m[words[1]].size();j++){
                    if(m[words[1]][j]>=0){
                        answer[m[words[1]][j]] = (words[2]+"님이 들어왔습니다.");
                    }
                    else{
                        answer[-m[words[1]][j]] = (words[2]+"님이 나갔습니다.");
                    }
                }
                m[words[1]].push_back(index++);
                answer.push_back(words[2]+"님이 들어왔습니다.");
            }
            m2[words[1]] = words[2];
        }
        else if(words[0] == "Leave"){
            m[words[1]].push_back(-index++);
            answer.push_back(m2[words[1]]+"님이 나갔습니다.");
        }
        else{
            for(int j=0;j<m[words[1]].size();j++){
                    if(m[words[1]][j]>=0){
                        answer[m[words[1]][j]] = (words[2]+"님이 들어왔습니다.");
                    }
                    else{
                        answer[-m[words[1]][j]] = (words[2]+"님이 나갔습니다.");
                    }
                }
            m2[words[1]] = words[2];
        }
        
    }
    
    return answer;
}