import java.util.Scanner;

public class Main {
	static int N,M;
	static int[] switches;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		switches = new int[N+1];
		for(int i=1;i<=N;i++) {
			switches[i] = sc.nextInt();
		}
		M = sc.nextInt();
		for(int i=0;i<M;i++) {
			int gender = sc.nextInt();
			int index = sc.nextInt();
			solve(gender,index);
			
		}
		for(int i=1;i<=N;i++) {
			System.out.print(switches[i]+" ");
			if(i%20==0) {
				System.out.println();
			}
		}
	}
	static void solve(int g,int idx) {
		if(g == 1) {
			int tmp=idx;
			while(tmp<=N) {
				switches[tmp] = Math.abs(switches[tmp]-1);
				tmp+=idx;
			}
		}
		else {
			int i=1;
			switches[idx] = Math.abs(switches[idx]-1);
			while(idx+i<=N && idx-i>0 && switches[idx+i] == switches[idx-i]) {
				switches[idx-i] = Math.abs(switches[idx-i]-1);
				switches[idx+i] = Math.abs(switches[idx+i]-1);
				i++;
			}
		}
	}
}