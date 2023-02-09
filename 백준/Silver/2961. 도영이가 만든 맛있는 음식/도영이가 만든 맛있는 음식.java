import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int arr[][];
	static boolean selected[];
	static int min = (int) 1e9;
	public static void main(String[] args) throws IOException {
		solve();
	    
	}
	static void solve() throws IOException {
		input();
		solution(0);
		System.out.println(min);
	}
	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    
	    N = Integer.parseInt(br.readLine());
	    arr = new int[N][2];
	    selected = new boolean[N];
	    
	    for(int i=0;i<N;i++) {
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	arr[i][0] = Integer.parseInt(st.nextToken());
	    	arr[i][1] = Integer.parseInt(st.nextToken());
	    	
	    	
	    }



	}
	static void solution(int cnt) {
		if(cnt == N) {
			min = Math.min(min,calculateBS());
			return;
		}
		selected[cnt] = true;
		solution(cnt+1);
		selected[cnt] = false;
		solution(cnt+1);
	}
	static int calculateBS() {
		int s=1,b=0;
		boolean flag=false;
		for(int i=0;i<N;i++) {
			if(selected[i]) {
				flag = true;
				s*=arr[i][0];
				b+=arr[i][1];
			}
		}
		if(!flag)
			return (int)1e9;
		return Math.abs(s-b);
	}

}