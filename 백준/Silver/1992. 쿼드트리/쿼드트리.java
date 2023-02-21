import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	static int N;
	static int[][] arr;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder("");
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws Exception {
		solve();
	}

	static void solve() throws Exception {
		input();
		solution(N, 0, 0);
		output();
	}

	static void output() throws Exception {
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

	static void input() throws Exception, Exception {
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < N; j++) {
				arr[i][j] = s.charAt(j);
			}
		}
	}

	static void solution(int n, int x, int y) {
		if (n == 1) {
			sb.append(arr[x][y]-'0');
			return;
		}
		int tmp = check(n, x, y);
		if (tmp != -1) {
			sb.append(tmp);
		} else {
			sb.append('(');
			solution(n / 2, x, y);
			solution(n / 2, x, y + n / 2);
			solution(n / 2, x + n / 2, y);
			solution(n / 2, x + n / 2, y + n / 2);
			sb.append(')');
		}

	}

	static int check(int n, int x, int y) {
		int tmp = arr[x][y];
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (arr[i][j] != tmp) {
					return -1;
				}
			}
		}
		return tmp-'0';
	}

}