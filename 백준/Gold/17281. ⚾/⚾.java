import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, ans;
    static int[][] inning;
    static int[] order = new int[9];
    static boolean[] selected = new boolean[9];

    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        input();
        //test();
        order[3] = 0;
        selected[3] = true;
        setOrder(1);
        System.out.println(ans);
    }

    private static void test() {
        order = new int[]{4, 5, 6, 0, 1, 2, 3, 7, 8};
        for (int i = 0; i < 9; i++) {
            System.out.print(inning[0][order[i]] + " ");
        }
        System.out.println();
        calculateResult();
    }

    private static void setOrder(int cnt) {
        if (cnt == 9) {
            ans = Math.max(calculateResult(), ans);
           // System.out.println(Arrays.toString(order));
            return;
        }

        for (int i = 0; i < 9; i++) {
            if (!selected[i]) {
                selected[i] = true;
                order[i] = cnt;
                setOrder(cnt + 1);
                selected[i] = false;
            }
        }

    }

    private static int calculateResult() {
        int sum = 0;
        int cur = 0;
        for (int i = 0; i < N; i++) {
            int out = 0;
            int roux = 0;
            while (out < 3) {

                int tmp = inning[i][order[cur]];

                if (tmp == 0) {
                    out++;
                    cur++;
                    cur %= 9;
                    continue;
                }
                roux = (roux + 1) << tmp;
                sum += Integer.bitCount(roux / 16);
                roux %= 16;
                cur++;
                cur %= 9;

            }
        }
        return sum;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        inning = new int[N][9];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                inning[i][j] = Integer.parseInt(st.nextToken());
            }
        }

    }
}