#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ssum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        if(type == 1) {
            ssum[r1][c1] -= degree;
            ssum[r1][c2 + 1] += degree;
            ssum[r2 + 1][c1] += degree;
            ssum[r2 + 1][c2 + 1] -= degree;
        }
        else {
            ssum[r1][c1] += degree;
            ssum[r1][c2 + 1] -= degree;
            ssum[r2 + 1][c1] -= degree;
            ssum[r2 + 1][c2 + 1] += degree;
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size() - 1; j++) {
            ssum[i][j + 1] += ssum[i][j];
        }
    }
    
    for(int i = 0; i < board[0].size(); i++) {
        for(int j = 0; j < board.size() - 1; j++) {
            ssum[j + 1][i] += ssum[j][i];
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            //cout<<ssum[i][j]<<" ";
            if(ssum[i][j] + board[i][j] > 0) {
                answer++;
            }
        }
        //cout<<endl;
    }
    
    return answer;
}