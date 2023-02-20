import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N,r,c,cnt,size;
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		solve();
		
	}
	static void solve() throws Exception {
		input();
		System.out.println(solution(N,0,0,0));
	}
	static void input() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		size = (int) Math.pow(2, N)*(int) Math.pow(2, N);

		
	}
	static int solution(int n,int x,int y, int ret) {
		if(n==0) {
			return ret;
		}
		if(r>=x+(int) Math.pow(2, n)/2&&c>=y+(int) Math.pow(2, n)/2) 
			return solution(n-1,x+(int) Math.pow(2, n)/2,y+(int) Math.pow(2, n)/2,(int) (ret+size/Math.pow(4,(N+1-n))*3));
		else if(r>=x+(int) Math.pow(2, n)/2&&c<y+(int) Math.pow(2, n)/2) 
			return solution(n-1,x+(int) Math.pow(2, n)/2,y,(int) (ret+size/Math.pow(4,(N+1-n))*2));
		else if(r<x+(int) Math.pow(2, n)/2&&c>=y+(int) Math.pow(2, n)/2)
			return solution(n-1,x,y+(int) Math.pow(2, n)/2,(int) (ret+size/Math.pow(4,(N+1-n))));
		else
			return solution(n-1,x,y,ret);
	}

}