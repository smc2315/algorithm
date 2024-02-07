#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;

bool check_same(int n, int m, vector<string> &board) {
    char c = board[n][m];
    if(c == '0')
        return false;
    for(int i = n; i < n + 2; i++) {
        for(int j = m; j < m + 2; j++) {
            if(board[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}

bool erase_block(int n, int m, vector<string> & board) {
    bool check = false;
    vector<pair<int, int>> to_erase;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(check_same(i, j, board)) {
                to_erase.push_back({i, j});
                check = true;
            }
        }
    }
    
    for(int i = 0; i < to_erase.size(); i++) {
        auto cur = to_erase[i];
        for(int j = cur.first; j < cur.first + 2; j++) {
            for(int k = cur.second; k < cur.second + 2; k++) {
                if(board[j][k] != '0') {
                    board[j][k] = '0';
                    answer++;
                }
            }
        }
    }
    return check;
}

void fall(int n, int m, vector<string> &board) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == '0') {
                int x = i - 1;
                while (x > 0 && board[x][j] == '0') {
                    x--;
                }
                swap(board[i][j], board[x][j]);
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    while(erase_block(m, n, board)) {
        fall(m, n, board);
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    return answer;
}