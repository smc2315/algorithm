import java.util.Scanner;

public class Main {

	static int N,M,a,b;
	static int arr[];
	public static void main(String[] args) {
		solve();
	}
	private static void solve() {
		input();
		
	}
	private static void input() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[N+1];
		for(int i=1;i<=N;i++) {
			
			arr[i] =arr[i-1]+ sc.nextInt();
		}
		for(int i=0;i<M;i++) {
			a= sc.nextInt();
			b= sc.nextInt();
			getSum();
		}
	}
	private static void getSum() {
		System.out.println(arr[b]-arr[a-1]);
	}

}