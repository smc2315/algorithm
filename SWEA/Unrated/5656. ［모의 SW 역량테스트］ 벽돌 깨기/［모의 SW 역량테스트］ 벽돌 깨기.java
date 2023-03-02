import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static int N, W, H,total;
    static int[][] map;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        //test();
        solve();

    }

    private static void test() throws IOException {
        input();
        int cnt=0;
        cnt+=breakBrick(2,map);
        System.out.println(cnt);
        fall(map);
        for (int i = 0; i < H; i++) {
            System.out.println(Arrays.toString(map[i]));
        }
        System.out.println();
        cnt+=breakBrick(2,map);
        System.out.println(cnt);
        fall(map);
        for (int i = 0; i < H; i++) {
            System.out.println(Arrays.toString(map[i]));
        }
        System.out.println();
        cnt+=breakBrick(6,map);
        fall(map);
        for (int i = 0; i < H; i++) {
            System.out.println(Arrays.toString(map[i]));
        }
        System.out.println(total-cnt);
        System.out.println(total+" "+cnt);
    }

    private static void solve() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            input();
            System.out.println("#"+t+" "+(total-selectBall(0,map)));
        }
    }

    private static int selectBall(int cnt,int[][] arr) {
        if(cnt == N){
            return 0;
        }
        int ret = 0;
        for (int i = 0; i < W; i++) {

            int[][] tmp = new int[H][W];
            for (int j = 0; j < H; j++) {
                tmp[j] = arr[j].clone();
            }
            int broke = breakBrick(i,tmp);
            if(broke!=0){
                fall(tmp);
            }
            ret = Math.max(ret,broke+selectBall(cnt+1,tmp));
        }
        return ret;

    }

    private static void fall(int[][] tmp) {
        for (int i = 0; i < H-1; i++) {
            for (int j = 0; j < W; j++) {
                if(tmp[i][j]!=0 && tmp[i+1][j] == 0){
                    for (int k = i; k >=0 ; k--) {
                        tmp[k+1][j] = tmp[k][j];
                    }
                    tmp[0][j]=0;
                }
            }
        }
    }

    private static int breakBrick(int n, int[][] tmp) {
        int cnt=0;
        int[] start = {-1,-1};
        for (int i = 0; i < H; i++) {
            if(tmp[i][n] !=0) {
                start = new int[]{i, n};
                break;
            }
        }
        if(start[0] == -1){
            return 0;
        }
        Queue<int[]> q = new ArrayDeque<>();
        q.add(start);
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int size = tmp[cur[0]][cur[1]];
            if(size==0)
                continue;
            tmp[cur[0]][cur[1]] = 0;
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = cur[0];
                int ny = cur[1];
                for (int j = 0; j < size - 1; j++) {
                    nx += dx[i];
                    ny+=dy[i];
                    if(nx>=0 && ny>=0 && nx<H&&ny<W&&tmp[nx][ny]!=0){
                        if(tmp[nx][ny]==1) {
                            tmp[nx][ny] = 0;
                            cnt++;
                        }
                        else{
                            q.add(new int[]{nx,ny});
                        }
                    }
                }
            }
        }
        return cnt;
    }

    private static void input() throws IOException {
        total = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        map = new int[H][W];
        for (int i = 0; i < H; i++) {
            st= new StringTokenizer(br.readLine());
            for (int j = 0; j < W; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]!=0)
                    total++;
            }
        }
    }
}