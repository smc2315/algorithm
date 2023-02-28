import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;



public class Main {
    static int N,min=(int)1e9;
    static int[] arr;
    static boolean selected[],visited[];
    static ArrayList<Integer>[] info;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new int[N+1];
        info = new ArrayList[N+1];
        for(int i = 1; i <= N; ++i) {
            info[i] = new ArrayList<Integer>();
        }
        selected = new boolean[N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int tmp = Integer.parseInt(st.nextToken());
            while(tmp-- != 0)
                info[i].add(Integer.parseInt(st.nextToken()));
        }
        solve();
    }
    static void solve() {
        divide(1);
        System.out.println(min==(int)1e9?-1:min);
    }

    private static void divide(int cnt) {
        if(cnt == N+1) {
            //System.out.println(Arrays.toString(selected));
            calculate();
            return;
        }
        selected[cnt] = false;
        divide(cnt+1);
        selected[cnt] = true;
        divide(cnt+1);
    }

    private static void calculate() {
        int a=0,b=0;
        boolean tmp = selected[1];
        boolean ret = false;
        for(int i=2;i<N+1;i++){
            if(tmp!=selected[i]){
                ret = true;
                break;
            }
        }
        if(!ret)
            return;

        for(int i = 1; i < N+1; i++){
            if(selected[i]){
                if((a=dfs(i,true))==-1){
                    return;
                }
                break;
            }
        }
        for(int i = 1; i < N+1; i++){
            if(!selected[i]){
                if((b=dfs(i,false))==-1){
                    return;
                }
                break;
            }
        }
       // System.out.println(Math.abs(a-b));
        min = Math.min(min,Math.abs(a-b));

    }

    private static int dfs(int n,boolean flag) {
        visited = new boolean[N+1];
        Stack<Integer> stk = new Stack<Integer>();
        stk.push(n);

        visited[n] = true;
        int sum=0;
        sum+=arr[n];
        while(!stk.isEmpty()){
            int cur = stk.pop();
            for(int i=0;i<info[cur].size();i++){
                if(selected[info[cur].get(i)] == flag && !visited[info[cur].get(i)]){
                    visited[info[cur].get(i)] = true;
                    stk.push(info[cur].get(i));
                    sum+=arr[info[cur].get(i)];
                }
            }
        }
        for(int i=1;i<=N;i++){
            if((selected[i]==flag)!=visited[i])
                return -1;
        }
        return sum;
    }
}