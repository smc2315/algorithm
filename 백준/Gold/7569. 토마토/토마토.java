import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
    static class Node {
        int x, y,z;

        public Node(int x, int y,int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    static int N, M,H, total;
    static int[][][] arr;
    static int[] dx = {0, 0, 1, -1, 0, 0};
    static int[] dy = {0, 0, 0, 0, 1, -1};
    static int[] dz = {1, -1, 0, 0, 0, 0};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Queue<Node> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        solve();

    }

    private static void solve() throws IOException {
        input();
        System.out.println(bfs());
    }

    private static int bfs() {
        int cnt = 0;
        int day = -1;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- != 0) {
                Node cur = q.poll();
                for (int i = 0; i < 6; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    int nz = cur.z +dz[i];
                    if (nx >= 0 && ny >= 0 && nz>=0 && nx < H && ny < N && nz<M && arr[nx][ny][nz] == 0) {
                        arr[nx][ny][nz] = 1;
                        q.add(new Node(nx, ny,nz));
                        cnt++;
                    }
                }
            }
            day++;
        }
        if (total == cnt)
            return day;
        else return -1;
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        arr = new int[H][N][M];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());
                    if (arr[i][j][k] == 0)
                        total++;
                    else if (arr[i][j][k] == 1)
                        q.add(new Node(i, j,k));

                }

            }
        }

    }
}