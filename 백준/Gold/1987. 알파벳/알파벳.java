import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	static int[][] map;
	static int N, M, ans;

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = s.charAt(j) - 'A';
			}
		}
		bfs();
		System.out.println(ans);

	}

	static void bfs() {
		Stack<int[]> q = new Stack<>();
		q.add(new int[] { 0, 0, 1, 1 << map[0][0] });

		while (!q.isEmpty()) {
			int[] cur = q.pop();
			ans = Math.max(ans, cur[2]);
			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && (((1 << map[nx][ny])) & cur[3]) != (1 << map[nx][ny])) {
					q.add(new int[] { nx, ny, cur[2] + 1, cur[3] | 1 << map[nx][ny] });
					
				}
			}
		}
	}
}