import java.util.Scanner;

public class Main {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ans = 0;
		int N = sc.nextInt();
		boolean arr[][] = new boolean[101][101];
		while(N--!=0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			for(int i=a;i<a+10;i++) {
				for(int j=b;j<b+10;j++) {
					if(!arr[i][j]) {
						arr[i][j] = true;
						ans++;
					}
				}
			}
		}
		
		
		
		System.out.println(ans);
		
	}

}