
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
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

    static int N;
    static Node shark;
    static int size = 2;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 0, 1};
    static int[] dy = {0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        solve();

        //test();
    }

    private static void test() throws IOException {
        size=3;
        input();
        findFish();
        print();
    }
    private static void print(){
        System.out.println();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }
    private static void solve() throws IOException {
        input();
        int time = 0;
        while (true) {
            for (int i = 0; i < size; i++) {

                int tmp=findFish();
                if (tmp==-1) {
                    System.out.println(time);
                    return;
                }
                
                time+=tmp;
            }
            size++;
        }
    }

    private static int findFish() {
        int cnt=0;
        int ret=-1;
        Node fish = null;
        visited = new boolean[N][N];
        Queue<Node> q = new ArrayDeque<>();
        q.add(shark);
        visited[shark.x][shark.y] = true;
        while (!q.isEmpty()) {
            int qsize = q.size();
            while(qsize--!=0) {
                Node cur = q.poll();
                if (map[cur.x][cur.y] > 0 && map[cur.x][cur.y] < size) {
                    if(ret==-1) {
                        ret = cnt;
                        fish = cur;
                    }
                    else {
                        if(fish.x>cur.x){
                            fish = cur;
                        }
                        else if(fish.x==cur.x){
                            if(fish.y>cur.y){
                                fish = cur;
                            }
                        }
                    }

                }
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && map[nx][ny] <= size) {
                        visited[nx][ny] = true;
                        q.add(new Node(nx, ny));
                    }
                }
            }
            if(ret!=-1){
                break;
            }
            cnt++;
        }
        if(ret !=-1){
            shark=fish;
            map[fish.x][fish.y] = 0;
        }
        return ret;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9) {
                    shark = new Node(i, j);
                    map[i][j] = 0;
                }
            }
        }
    }
}
