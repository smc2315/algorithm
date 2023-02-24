import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int V, E, ans=-1;
	static ArrayList<Integer>[] arr;
	static boolean visited[];

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		arr = new ArrayList[V];
		visited = new boolean[V];
		for (int i = 0; i < V; ++i) {
			arr[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < E; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			arr[a].add(b);
			arr[b].add(a);
		}

		bfs(0);
		System.out.println(ans);
	}

	static void bfs(int n) {
		Queue<Integer> q = new ArrayDeque<>();
		q.add(n);
		visited[n] = true;
		while (!q.isEmpty()) {
			int cur = q.poll();
			ans++;
			for (int i = 0; i < arr[cur].size(); i++) {
				if (!visited[arr[cur].get(i)]) {
					q.add(arr[cur].get(i));
					visited[arr[cur].get(i)] = true;
				}
			}
		}

	}

}