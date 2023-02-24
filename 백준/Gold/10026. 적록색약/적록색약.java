import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	static int N, cnt, cnt2;
	static char[][] map;
	static boolean[][] visited;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[] dx = { -1, 0, 1, 0 }, dy = { 0, -1, 0, 1 };

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		map = new char[N][N];
		visited = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String tmp = br.readLine();
			for (int j = 0; j < N; j++) {
				char c = tmp.charAt(j);
				map[i][j] = c;

			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
					cnt2++;

				}
			}
		}

		visited = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs2(i, j);
					cnt++;

				}
			}
		}
		System.out.println(cnt + " " + cnt2);
	}

	static void bfs(int x, int y) {
		Queue<int[]> q = new ArrayDeque<>();
		q.add(new int[] { x, y });
		visited[x][y] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			char c = map[cur[0]][cur[1]];
			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
					if (c == map[nx][ny] || Math.abs(c - map[nx][ny]) == 11) {
						q.add(new int[] { nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}

	static void bfs2(int x,int y) {

		Queue<int[]> q = new ArrayDeque<>();
		q.add(new int[] { x, y });
		visited[x][y] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			char c = map[cur[0]][cur[1]];
			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
					if (c == map[nx][ny]) {
						q.add(new int[] { nx, ny });
						visited[nx][ny] = true;
					} 
				}
			}
		}

	

	}

}