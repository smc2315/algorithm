import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

class Point{
	int x,y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	@Override
    public int hashCode() {
        int result = 17;
        result = 31 * result + x;
        result = 31 * result + y;
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (!(obj instanceof Point)) {
            return false;
        }
        Point other = (Point) obj;
        return x == other.x && y == other.y;
    }
	
}

public class Main {

	static int N, M, D,kill, ans;
	static int[][] map;
	static int[][] tmp;
	static boolean[] position;
	static int[] dx = { 0, -1, 0 };
	static int[] dy = { -1, 0, 1 };
	static boolean[][] visited;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		map = new int[N + 1][M];

		position = new boolean[M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve();
	}

	static void solve() {
		setArcher(0, 0);
		System.out.println(ans);
	}

	static void setArcher(int cnt, int s) {
		if (cnt == 3) {
			startGame();
			return;
		}
		for (int i = s; i < M; i++) {
			position[i] = true;
			setArcher(cnt + 1, i + 1);
			position[i] = false;
		}
	}

	static void startGame() {
		kill = 0;
		tmp = new int[N + 1][M];
		for (int i = 0; i < N; i++) {
			tmp[i] = map[i].clone();
		}
		while (!isMapEmpty()) {
			attack();
			
			move();
			
		}
		ans = Math.max(kill, ans);
	}

	static boolean isMapEmpty() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	static void attack() {
		Set<Point> monsters = new HashSet<>();
		for (int i = 0; i < M; i++) {
			if (position[i]) {
				visited = new boolean[N + 1][M];
				Queue<int[]> q = new ArrayDeque<>();
				q.add(new int[] { N, i,0 });
				visited[N][i] = true;
				while (!q.isEmpty()) {
					int[] cur = q.poll();
					if(tmp[cur[0]][cur[1]]==1) {
						monsters.add(new Point(cur[0],cur[1]));
						break;
					}
					if(cur[2] == D)
						continue;
					for (int j = 0; j < 3; j++) {
						int nx = cur[0] + dx[j];
						int ny = cur[1] + dy[j];
						if (nx >= 0 && ny >= 0 && nx < N + 1 && ny < M && !visited[nx][ny]) {
							q.add(new int[]{nx,ny,cur[2]+1});
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
		Iterator<Point> it = monsters.iterator();
		while (it.hasNext()) {
			Point temp = it.next();
			//System.out.print(N+""+temp[1]+" ");
			tmp[temp.x][temp.y] = 0;
			kill++;
		}

	}

	static void move() {
		for(int i=N-1;i>=1;i--) {
			for(int j=0;j<M;j++) {
				if(i==N-1) {
					if(tmp[i][j]==1) {
						tmp[i][j] = 0;
					}
				}
				if(tmp[i-1][j] == 1) {
					tmp[i][j] = 1;
					tmp[i-1][j] = 0;
				}
			}
		}
	}

}