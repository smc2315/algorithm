import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    int index,dis;

    public Node(int index, int dis) {
        this.index = index;
        this.dis = dis;
    }


}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine())-1;
        List<Node>[] arr;
        arr= new ArrayList[V];
        for (int i = 0; i < V; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            arr[Integer.parseInt(st.nextToken())-1].add(new Node(Integer.parseInt(st.nextToken())-1,Integer.parseInt(st.nextToken())));
        }

        final int INF = Integer.MAX_VALUE;
        int[] distance = new int[V];

        Arrays.fill(distance, INF);
        distance[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.dis));
        pq.add(new Node(start,0));

        while(!pq.isEmpty()){
            Node cur =  pq.poll();
            if(distance[cur.index] < cur.dis) continue;
            for(Node node : arr[cur.index]){
                if(distance[node.index] > distance[cur.index] + node.dis){
                    distance[node.index] = distance[cur.index] + node.dis;
                    
                    pq.add(new Node(node.index,distance[node.index]));
                }
            }
        }
        for (int i = 0; i < V; i++) {
            System.out.println(distance[i]!=INF?distance[i]:"INF");
        }

    }
}