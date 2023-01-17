#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            answer+=new_id[i]+32;
        }
        else if((new_id[i]>='a'&&new_id[i]<='z') || (new_id[i]>=48&&new_id[i]<=57)||(new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.')){
            answer+=new_id[i];
        }
        
        
            
    }
    string answer2="";
    for(int i=0;i<answer.size();i++){
        if(answer[i]=='.'){
            answer2+='.';
            while(i<answer.size()&&answer[i]=='.'){
                i++;
                }
            i--;
        }
        else
            answer2+=answer[i];
    }
    if(answer2[0] == '.'){
        answer2=answer2.substr(1,answer2.size());
    }
    if(answer2[answer2.size()-1]=='.'){
        answer2 = answer2.substr(0,answer2.size()-1);
    }
    if(answer2==""){
        answer2+='a';
    }
    if(answer2.size()>=16){
        answer2=answer2.substr(0,15);
    }
    if(answer2[answer2.size()-1]=='.'){
        answer2 = answer2.substr(0,answer2.size()-1);
    }
    if(answer2.size()<=2){
        while(answer2.size()!=3){
            answer2+=answer2[answer2.size()-1];
        }
    }
    
    return answer2;
}