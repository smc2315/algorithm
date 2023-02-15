import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node implements Comparable<Node>{
	int first,second;

	@Override
	public int compareTo(Node o) {
		if(o.first == this.first) {
			return this.second-o.second;
		}
		return  this.first-o.first;
	}
	
}
public class Main {

	
	public static void main(String[] args) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i=0;i<N;i++) {
			int tmp=sc.nextInt();
			if(tmp!=0) {
				Node node = new Node();
				node.first = Math.abs(tmp);
				node.second = tmp;
				pq.add(node);
			}
			else {
				Node front = pq.poll();
				System.out.println(front!=null?front.second:0);
			}
		}
	}

}