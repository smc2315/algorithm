import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Shark {
    int s, d, z;

    public Shark(int s, int d, int z) {
        this.s = s;
        this.d = d;
        this.z = z;
    }
}

public class Main {
    static int R, C, M, ans;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static Shark[][] map;

    public static void main(String[] args) throws IOException {
        solve();
    }

    static void solve() throws IOException {
        input();
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= R; j++) {
                if (map[j][i] != null) {
                    ans+=map[j][i].z;
                    map[j][i] = null;
                    break;
                }
            }
            sharkMove();
//            for (int j = 1; j <= R; j++) {
//                for (int k = 1; k <= C ; k++) {
//
//                    System.out.print(map[j][k] == null?0+" ":map[j][k].z+" ");
//                }
//                System.out.println();
//
//            }
//            System.out.println();
        }
        System.out.println(ans);
    }


    private static void sharkMove() {
        Shark[][] tmp = new Shark[R + 1][C + 1];
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (map[i][j] != null) {
                    Shark cur = map[i][j];
                    int cr = i;
                    int cc = j;
                    for (int k = 0; k <cur.s; k++) {
                        int nr = cr + dx[cur.d-1];
                        int nc = cc + dy[cur.d-1];
                        if(nr<1||nc<1||nr>R||nc>C)
                            cur.d = changeDir(cur.d);
                        cr += dx[cur.d-1];
                        cc += dy[cur.d-1];

                    }
                    if(tmp[cr][cc] == null)
                        tmp[cr][cc] = cur;
                    else{
                        if(tmp[cr][cc].z<cur.z)
                            tmp[cr][cc] = cur;
                    }
                }
            }
        }
        map = tmp;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new Shark[R + 1][C + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            if(d == 1 || d == 2) s %= ((R-1) * 2);
            else s %= ((C - 1) * 2);
            map[r][c] = new Shark(s,d,z);
        }
    }
    static int changeDir(int x){
        if(x==1) return 2;
        if(x==2) return 1;
        if(x==3) return 4;
        else     return 3;
    }
}