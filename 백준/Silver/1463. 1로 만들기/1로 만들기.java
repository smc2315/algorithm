import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int[] memo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        memo = new int[N + 1];
        Arrays.fill(memo, -1);
        System.out.println(recur(N));
    }

    static int recur(int N) {
        if (N < 2) {
            return 0;
        }
        if (memo[N] != -1) {
            return memo[N];
        }
        int result = recur(N / 2) + 1 + (N % 2);
        result = Math.min(result, recur(N / 3) + 1 + (N % 3));
        memo[N] = result;
        return result;
    }
}