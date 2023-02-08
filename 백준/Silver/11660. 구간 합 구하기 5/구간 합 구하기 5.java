import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int N,M,x1,x2,y1,y2;
	static int arr[][],psum[][];
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException {
		solve();
		
	}
	private static void solve() throws IOException {
		input();
	}
	private static void input() throws IOException {
		 String[] tmp = br.readLine().split(" ");
	        N = Integer.parseInt(tmp[0]);
	        M = Integer.parseInt(tmp[1]);
	        arr = new int[N + 1][N + 1];
	        psum = new int[N + 1][N + 1];
	        
	        for(int i = 1; i <= N; i++) {
	            tmp = br.readLine().split(" ");
	            for (int j = 1; j <= N; j++) {
	                arr[i][j] = Integer.parseInt(tmp[j-1]);
	                psum[i][j] = psum[i-1][j] +psum[i][j-1] - psum
	                		[i-1][j-1]+arr[i][j];
	            }
	        }
		for(int i=0;i<M;i++) {
			tmp = br.readLine().split(" ");
            x1 = Integer.parseInt(tmp[0]);
            y1 = Integer.parseInt(tmp[1]);
            x2 = Integer.parseInt(tmp[2]);
            y2 = Integer.parseInt(tmp[3]);
			getSum();
		}
	}
	private static void getSum() {
		System.out.println(psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1]);
	}

}