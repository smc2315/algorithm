import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Node{
	int x,t;

	public Node(int x, int t) {
		this.x = x;
		this.t = t;
	}
	
}
public class Main {
	static int N,K;
	static boolean[] visited = new boolean[100001];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		BFS();
	}
	static void BFS() {
		Queue<Node> q = new ArrayDeque<Node>();
		q.add(new Node(N,0));
		visited[N] = true;
		while(!q.isEmpty()) {
			Node cur = q.poll();
			if(cur.x==K) {
				System.out.println(cur.t);
				return;
			}
			
			if(cur.x+1<=100000 && !visited[cur.x+1]) {
				q.add(new Node(cur.x+1,cur.t+1));
				visited[cur.x+1] = true;
			}
			if(cur.x-1>=0 && !visited[cur.x-1]) {
				q.add(new Node(cur.x-1,cur.t+1));
				visited[cur.x-1] = true;
			}
			if(cur.x*2 <=100000 && !visited[cur.x*2]) {
				q.add(new Node(cur.x*2,cur.t+1));
				visited[cur.x*2] = true;
			}
		}
	}

}