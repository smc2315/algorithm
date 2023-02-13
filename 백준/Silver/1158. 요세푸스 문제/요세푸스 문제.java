import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int N,K;
	static List<Integer> list;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		list = new ArrayList<>();
		for(int i=1;i<=N;i++) {
			list.add(i);
		}
		System.out.print("<");
		int cur = -1;
		int max = N;
		for(int i=0;i<N;i++) {
			cur = (cur+K)%max;
			System.out.print(list.get(cur));
			list.remove(cur);
			cur--;
			max--;
			if(i==N-1)
				System.out.println(">");
			else
				System.out.print(", ");
		}
	}

}