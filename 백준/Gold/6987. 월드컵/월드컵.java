import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder("");
	static StringTokenizer st;
	static long[] exp = { 1000000000000000L, 1000000000000L, 1000000000L, 1000000L, 1000L, 1L };
	static long result;


	public static void main(String[] args) throws IOException {
		for (int tc = 0; tc < 4; tc++) {
			result = Long.parseLong(br.readLine().replaceAll(" ", ""));
			sb.append((solve(0, 1,0) ? "1" : "0") + " ");
		}

		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

	public static boolean solve(int n,int m, long state) {
		if (n == 5)
			return state == result;

		if (state > result)
			return false;
		
		long win = state + 100 * exp[n] + exp[m];

		long draw = state + 10 * exp[n] + 10 * exp[m];

		long lose = state + exp[n] + 100 * exp[m];

		m++;
		if(m>=6) {
			n++;
			m=n+1;
		}
		return solve(n,m, win) || solve(n,m, draw) || solve(n,m, lose);
	}

}