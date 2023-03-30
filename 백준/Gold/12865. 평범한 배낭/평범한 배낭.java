import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N,K;
    static int[][] things;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        input();
        System.out.println(dfs(0,K));
    }

    private static int dfs(int n,int k) {
        if(n==N)
            return 0;
        if(dp[n][k]!=-1)
            return dp[n][k];
        if(things[n][0] > k)
            return dfs(n+1,k);
        return dp[n][k] = Math.max(dfs(n+1,k-things[n][0])+things[n][1],dfs(n+1,k));
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        things =  new int[N][2];
        dp = new int[N][K+1];
        for (int i = 0; i < N; i++)
            Arrays.fill(dp[i],-1);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            things[i][0] = Integer.parseInt(st.nextToken());
            things[i][1] = Integer.parseInt(st.nextToken());
        }
    }
}