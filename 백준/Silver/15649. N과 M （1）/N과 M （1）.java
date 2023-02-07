import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N,R;//nPr
	static int[] result,numbers;
	static boolean[] isSelected;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args)  throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
		StringTokenizer st = new StringTokenizer(br.readLine());
 
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		
		numbers = new int[N];
		result = new int[R];
		isSelected = new boolean[N];
		
		for(int i=0;i<N;i++) {
			numbers[i] =i+1;
		}
		
		perm(0);
        System.out.println(sb);
		
	}
	private static void perm(int cnt) {
		if(cnt == R) {
			
			for (int val : result) {
				sb.append(val).append(' ');
			}
			sb.append('\n');
			return;
		}
		for(int i=0;i<N;i++) {
			if(!isSelected[i]) {
				isSelected[i] = true;
				result[cnt] = numbers[i];
				
				perm(cnt+1);
				isSelected[i] = false;
				
			}
		}
	}

}