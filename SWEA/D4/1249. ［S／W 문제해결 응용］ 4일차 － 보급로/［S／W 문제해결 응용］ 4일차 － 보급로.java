import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {
    static class Node{
        int x,y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static final int INF = Integer.MAX_VALUE;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,-1,0,1};
    static int[][] map;
    static int[][] visited;
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for(int t = 1;t<=T;t++) {
            input();
            bfs();
            System.out.println("#"+t+" "+visited[N-1][N-1]);
        }
    }

    private static void bfs() {
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(0,0));
        visited[0][0] = 0;
        while(!q.isEmpty()){
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if(nx>=0 && ny>=0 && nx<N && ny < N){
                    
                    if(visited[nx][ny]>visited[cur.x][cur.y]+map[nx][ny]){
                        visited[nx][ny] = visited[cur.x][cur.y]+map[nx][ny];
                        q.add(new Node(nx,ny));
                    }
                }
            }
        }
    }

    private static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new int[N][N];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = tmp.charAt(j)-'0';
                visited[i][j] = INF;
            }

        }
    }
}