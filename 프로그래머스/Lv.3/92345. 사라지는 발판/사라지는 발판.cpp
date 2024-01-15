#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool visited[5][5];

int solve(int curx, int cury, int opx, int opy, vector<vector<int>> & board) {
    if(visited[curx][cury]) {
        return 0;
    }
    int ret = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if(!visited[nx][ny] && nx >= 0 && ny >=0 && nx < board.size() && ny < board[0].size() && board[nx][ny]) {
            visited[curx][cury] = true;
            
            int tmp = solve(opx, opy, nx, ny, board) + 1;
            
            visited[curx][cury] = false;
            
            if(ret % 2 == 0 && tmp % 2 == 1)
                ret = tmp;
            else if(ret % 2 == 0 && tmp % 2 == 0)
                ret = max(ret, tmp);
            else if(ret % 2 == 1 && tmp % 2 == 1) {
                ret = min(ret, tmp);
            }       
        }
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return solve(aloc[0], aloc[1], bloc[0], bloc[1], board);
}