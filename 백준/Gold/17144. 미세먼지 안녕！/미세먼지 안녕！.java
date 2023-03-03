import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int R, C, T, airRefresher;
    static int[][] arr;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        input();
        while (T-- != 0) {
            diffusion();
            refresh();
        }
        int ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] > 0)
                    ans += arr[i][j];
            }
        }

        System.out.println(ans);
    }

    private static void diffusion() {
        int[][] tmp = new int[R][C];
        for (int i = 0; i < R; i++) {
            tmp[i] = arr[i].clone();
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] > 0) {
                    int size = arr[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < R && ny < C && arr[nx][ny] != -1) {
                            tmp[nx][ny] += size;
                            tmp[i][j] -= size;

                        }
                    }
                }
            }
        }
        arr = tmp;
    }

    private static void refresh() {
        int up = airRefresher - 1;
        int down = airRefresher;
        for (int i = up - 1; i > 0; i--) {
            arr[i][0] = arr[i - 1][0];
        }
        for (int i = down + 1; i < R - 1; i++) {
            arr[i][0] = arr[i + 1][0];
        }

        for (int i = 0; i < C - 1; i++) {
            arr[0][i] = arr[0][i + 1];
        }
        for (int i = 0; i < C - 1; i++) {
            arr[R - 1][i] = arr[R - 1][i + 1];
        }
        for (int i = 0; i < up; i++) {
            arr[i][C - 1] = arr[i + 1][C - 1];
        }
        for (int i = R - 1; i > down; i--) {
            arr[i][C - 1] = arr[i - 1][C - 1];
        }

        for (int i = C - 1; i > 1; i--) {
            arr[up][i] = arr[up][i - 1];
            arr[down][i] = arr[down][i - 1];
        }
        arr[up][1] = 0;
        arr[down][1] = 0;


    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        arr = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == -1)
                    airRefresher = i;

            }
        }
    }

}