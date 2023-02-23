import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	static ArrayList<Integer>[] adjList;

	static int start, V;
	static boolean[] visited;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		int E = sc.nextInt();
		start = sc.nextInt();

		adjList = new ArrayList[V + 1];
		for (int i = 1; i <= V; ++i) {
			adjList[i] = new ArrayList<Integer>();
		}
		int from, to;
		for (int i = 0; i < E; ++i) {
			from = sc.nextInt();
			to = sc.nextInt();
			adjList[from].add(to);
			adjList[to].add(from);

		}
		visited = new boolean[V + 1];
		DFS(start);

		System.out.println();
		BFS();

	}

	static void DFS(int n) {
		visited[n] = true;
		System.out.print(n + " ");
		if (adjList[n] != null) {
			Collections.sort(adjList[n]);
			for (int i = 0; i < adjList[n].size(); i++) {
				if (!visited[adjList[n].get(i)]) {
					DFS(adjList[n].get(i));
				}
			}
		}

	}

	static void BFS() {
		Queue<Integer> q = new ArrayDeque<Integer>();
		visited = new boolean[V + 1];
		q.add(start);
		visited[start] = true;
		while (!q.isEmpty()) {
			int cur = q.poll();
			System.out.print(cur + " ");
			if (adjList[cur] != null) {

				for (int i = 0; i < adjList[cur].size(); i++) {
					if (!visited[adjList[cur].get(i)]) {
						q.add(adjList[cur].get(i));
						visited[adjList[cur].get(i)] = true;
					}
				}
			}
		}
	}

}