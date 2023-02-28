import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static int N, S;
    static int[][] map ;
    static boolean[] visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        for(int t=1;t<=10;t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());
            map = new int[101][101];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i += 2) {

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                map[a][b] = 1;
            }

            System.out.println("#"+t+" "+bfs());
        }

    }

    private static int bfs() {
        visited = new boolean[101];
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{S,0});
        visited[S] = true;
        int[] last = {-1,-1};
        while(!q.isEmpty()){
            int[] cur = q.poll();
            if (cur[1]>last[1])
                last = cur;
            else if(cur[1] == last[1]){
                if(cur[0]>last[0])
                    last= cur;
            }
            for(int i=0;i<101;i++){

                if(map[cur[0]][i] == 1 && !visited[i]){

                    q.add(new int[]{i,cur[1]+1});
                    visited[i] = true;
                }
            }
        }
        return last[0];

    }
}