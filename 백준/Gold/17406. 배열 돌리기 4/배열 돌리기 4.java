import java.io.*;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[][] arr = new int[51][51];
    static ArrayList<Tuple> v = new ArrayList<>();
    static boolean[] selected = new boolean[6];
    static int res = 1000000000;
    
    public static void move(int a, int b, int c) {
        if (c == 0) return;
        int tmp = arr[a - c][b - c];
        for (int i = a - c; i < a + c; i++) {
            arr[i][b-c] = arr[i + 1][b-c];
        }
        for (int j = b - c; j < b + c; j++) {
            arr[a + c][j] = arr[a + c][j + 1];
        }
        for (int i = a + c; i > a - c; i--) {
            arr[i][b + c] = arr[i - 1][b + c];
        }
        for (int j = b + c; j > b - c; j--) {
            arr[a - c][j] = arr[a - c][j - 1];
        }
        arr[a - c][b - c + 1] = tmp;

        move(a, b, c - 1);
    }
    
    public static void cal() {
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += arr[i][j];
            }
            res = Math.min(sum, res);
        }
    }
    
    public static void select_order(int n) {
        if (n == K) {
            cal();
            return;
        }
        for (int i = 0; i < K; i++) {
            if (!selected[i]) {
                selected[i] = true;
                int[][] tmp = new int[51][51];
                for (int j = 0; j < 51; j++) {
                    tmp[j] = Arrays.copyOf(arr[j], arr[j].length);
                }
                move(v.get(i).a, v.get(i).b, v.get(i).c);
                select_order(n + 1);
                for (int j = 0; j < 51; j++) {
                    arr[j] = Arrays.copyOf(tmp[j], tmp[j].length);
                }
                selected[i] = false;
            }
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            v.add(new Tuple(a, b, c));
        }
        select_order(0);
        System.out.println(res);
    }
    
    static class Tuple {
        int a, b, c;
        Tuple(int a,int b,int c){
            this.a=a;
            this.b=b;
            this.c=c;
        }
    }
}