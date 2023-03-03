import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
    int x, y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int N, M, total;
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
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
        int cnt=0;
        int day=-1;
        while (!q.isEmpty()) {
            int size = q.size();
            while(size--!=0) {
                Node cur = q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0) {
                        arr[nx][ny] = 1;
                        q.add(new Node(nx, ny));
                        cnt++;
                    }
                }
            }
            day++;
        }
        if(total == cnt)
            return day;
        else return -1;
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 0)
                    total++;
                else if (arr[i][j] == 1)
                    q.add(new Node(i, j));

            }

        }
    }
}