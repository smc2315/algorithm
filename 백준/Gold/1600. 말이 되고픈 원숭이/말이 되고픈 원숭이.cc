#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node{
    int x, y,k;

    Node(int x, int y, int k) {
        this->x = x;
        this->y = y;
        this->k = k;
    }
};

int K, W, H;
int arr[201][201];
int visited[201][201][31];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dhx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dhy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void input();
void initVisited();
int bfs();
bool isRange(int nx, int ny);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    initVisited();
    cout << bfs() << endl;
    return 0;
}

void input() {
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }
}

void initVisited() {
    memset(visited, -1, sizeof(visited));
}

int bfs() {
    queue<Node> q;
    q.push(Node(0, 0, 0));
    visited[0][0][0] = 0;

    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        if(cur.x == H-1 && cur.y == W-1){
            return visited[H-1][W-1][cur.k];
        }
        if(cur.k<K){
            for (int i = 0; i < 8; i++) {
                int nx = cur.x+dhx[i];
                int ny = cur.y+dhy[i];
                if(isRange(nx,ny) && visited[nx][ny][cur.k+1]==-1){
                    q.push(Node(nx,ny,cur.k+1));
                    visited[nx][ny][cur.k+1] = visited[cur.x][cur.y][cur.k]+1;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(isRange(nx,ny) && visited[nx][ny][cur.k]==-1){
                q.push(Node(nx,ny,cur.k));
                visited[nx][ny][cur.k] = visited[cur.x][cur.y][cur.k]+1;
            }
        }
    }
    return -1;
}

bool isRange(int nx, int ny) {
    return nx>=0 && ny>=0 && nx<H && ny<W && arr[nx][ny]!=1;
}