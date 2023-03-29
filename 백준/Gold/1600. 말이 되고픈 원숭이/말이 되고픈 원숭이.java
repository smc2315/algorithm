import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        int x, y,k;

        public Node(int x, int y, int k) {
            this.x = x;
            this.y = y;
            this.k = k;
        }
    }
    static int K, W, H;
    static int[][] arr;
    static int[][][] visited;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static int[] dhx = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int[] dhy = {-1, 1, -2, 2, -2, 2, -1, 1};

    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        input();
        initVisited();
        System.out.println(bfs());
    }

    private static void initVisited() {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k <= K; k++) {
                    visited[i][j][k] = -1;
                }
            }
        }
    }

    private static int bfs() {
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(0,0,0));
        visited[0][0][0] = 0;
        while(!q.isEmpty()){
            Node cur = q.poll();
            if(cur.x == H-1 && cur.y == W-1){
                return visited[H-1][W-1][cur.k];
            }
            if(cur.k<K){
                for (int i = 0; i < 8; i++) {
                    int nx = cur.x+dhx[i];
                    int ny = cur.y+dhy[i];
                    if(isRange(nx,ny) && visited[nx][ny][cur.k+1]==-1){
                        q.add(new Node(nx,ny,cur.k+1));
                        visited[nx][ny][cur.k+1] = visited[cur.x][cur.y][cur.k]+1;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if(isRange(nx,ny) && visited[nx][ny][cur.k]==-1){
                    q.add(new Node(nx,ny,cur.k));
                    visited[nx][ny][cur.k] = visited[cur.x][cur.y][cur.k]+1;
                }
            }

        }

        return -1;
    }

    private static boolean isRange(int nx, int ny) {
        return nx>=0 && ny>=0 &&nx<H&&ny<W &&arr[nx][ny]!=1;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        K = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        arr = new int[H][W];
        visited = new int[H][W][K+1];
        for (int i = 0; i < H; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < W; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }

        }
    }
}