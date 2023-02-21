import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int R, C, ans;
	static char[][] arr;

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		solve();
	}

	static void solve() throws Exception {
		input();
		for(int i=0;i<R;i++) {
			solution(i, 0);
		}
		System.out.println(ans);
	}

	static void input() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new char[R][C];
		for (int i = 0; i < R; i++) {
			String tmp = br.readLine();
			for (int j = 0; j < C; j++) {
				arr[i][j] = tmp.charAt(j);
			}
		}
	}

	static boolean solution( int s, int depth) {
		if(depth == C-1) {
			ans++;
			return true;
		}
		for(int i=0;i<3;i++) {
			int nx = s+i-1;
			if(nx>=0&&nx<R&&arr[nx][depth+1]!='x') {
				arr[nx][depth+1] = 'x';
				if(solution(nx,depth+1)) {
					return true;
				}
			}
		}
		return false;
		

	}

}