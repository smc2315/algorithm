import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

    static int N,M,C,ans;
    static int[][] arr;
    static ArrayList<Integer>[] honey ;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T ; t++) {
            input();
            select(0,0,0);
            System.out.println("#"+t+" "+ans);
        }

    }

    private static void select(int cnt, int x, int y) {
        if(cnt==2){
            ans = Math.max(ans,count());
            return;
        }
        for (int i = x; i < N; i++) {
            for (int j = 0; j <= N-M; j++) {
                if(i==x&&j<y)
                    continue;
                for (int k = j; k < j+M; k++) {
                    honey[cnt].add(arr[i][k]);
                }
                select(cnt+1,i,j+M);
                honey[cnt].clear();
            }
        }
    }

    private static int count() {
        int ret = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = M; j >=0 ; j--) {
                int sum = addHoney(0,0,j,i,0);


                if(sum<(int)1e9) {
                    ret += sum;
                    break;
                }

            }
        }

        return ret;
    }

    private static int addHoney(int s,int cnt, int n,int index,int sum) {
        if(sum>C)
            return -(int)1e9;
        if(cnt == n){
                return 0;


        }
        int ret = 0;
        for (int i = s; i < M; i++) {
            int tmp = honey[index].get(i);
            int tmp2 = addHoney(i+1,cnt+1,n,index,sum+tmp);
            ret = Math.max(ret, tmp2 + tmp * tmp);
        }

        return ret;
    }


    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M =Integer.parseInt(st.nextToken());
        C =Integer.parseInt(st.nextToken());
        arr = new int[N][N];
        honey = new ArrayList[2];
        ans=0;
        for (int i = 0; i < 2; i++) {
            honey[i]  = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j]= Integer.parseInt(st.nextToken());
            }
        }
    }
}