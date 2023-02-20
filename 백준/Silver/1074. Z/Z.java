import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N,r,c,cnt;
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		solve();
		
	}
	static void solve() throws Exception {
		input();
		System.out.println(solution((int) Math.pow(2, N)*(int) Math.pow(2, N),0,0,0));
	}
	static void input() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		
	}
	static int solution(int n,int x,int y, int ret) {
		if(n==1) {
			return ret;
		}
		if(r>=x+n/2&&c>=y+n/2) 
			return solution(n/2,x+n/2,y+ n/2,ret+n*n/4*3);
		else if(r>=x+n/2&&c<y+n/2) 
			return solution(n/2,x+n/2,y,ret+n*n/2);
		else if(r<x+n/2&&c>=y+n/2)
			return solution(n/2,x,y+n/2,ret+n*n/4);
		else
			return solution(n/2,x,y,ret);
	}

}