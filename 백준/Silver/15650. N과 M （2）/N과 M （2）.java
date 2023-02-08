import java.util.Scanner;

public class Main {
	static int N, M;
	static int[] arr, result;
	static boolean[] selected;

	public static void main(String[] args) {
		solve();
	}

	private static void solve() {
		input();
		combi(0, 0);
	}

	private static void input() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[N];
		result = new int[M];
		selected = new boolean[N];
		for (int i = 0; i < N; i++) {
			arr[i] = i + 1;
		}
	}

	private static void output() {
		for (int i = 0; i < M; i++) {
			System.out.print(result[i] + " ");
		}
		System.out.println();
	}

	private static void combi(int cnt, int s) {
		if (cnt == M) {
			output();
			return;
		}
		for (int i = s; i < N; i++) {
			if (!selected[i]) {
				selected[i] = true;
				result[cnt] = arr[i];
				combi(cnt + 1, i + 1);
				selected[i] = false;
			}
		}
	}

}