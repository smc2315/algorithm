#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[5][5];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dx2[4] = {0,0,-2,2};
int dy2[4] = {-2,2,0,0};

int dx3[4] = {-1,-1,1,1};
int dy3[4] = {-1,1,-1,1};
bool check(){
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j] == 1){
               for(int k=0;k<4;k++){
                   int nx = i+dx[k];
                   int ny = j+dy[k];
                   
                   int nx2 = i+dx2[k];
                   int ny2 = j+dy2[k];
                   
                   int nx3 = i+dx3[k];
                   int ny3 = j+dy3[k];
                   
                   if(nx>=0&&ny>=0&&nx<5&&ny<5){
                       if(arr[nx][ny] == 1){
                           cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<endl;
                           return false;
                           
                       }
                   }
                   if(nx2>=0&&ny2>=0&&nx2<5&&ny2<5){
                       if(arr[nx2][ny2]==1&&arr[(nx2+i)/2][(ny2+j)/2]!=-1){
                           cout<<i<<" "<<j<<" "<<nx2<<" "<<ny2<<endl;
                           return false;
                       }
                   }
                   if(nx3>=0&&ny3>=0&&nx3<5&&ny3<5){
                       if(arr[nx3][ny3]==1&&(arr[nx3][j]==0 || arr[i][ny3]==0)){
                           cout<<i<<" "<<j<<" "<<nx3<<" "<<ny3<<endl;
                           return false;
                       }
                   }
               }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k] == 'P')
                    arr[j][k] = 1;
                else if(places[i][j][k] == 'X')
                    arr[j][k] = -1;
                else
                    arr[j][k] = 0;
            }
        }
        
        bool flag = check();
        if(flag){
            answer.push_back(1);
        }
        else
            answer.push_back(0);
    }
    
    
    return answer;
}