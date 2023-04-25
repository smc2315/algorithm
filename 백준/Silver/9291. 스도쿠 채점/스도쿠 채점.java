import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main {
    
    static int T;
    static int[][] map;
    static boolean[] visited;
    static int[] dx = {0,0,0,3,3,3,6,6,6};
    static int[] dy = {0,3,6,0,3,6,0,3,6};
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        T = Integer.parseInt(br.readLine());
        int t = 1;
        
        while(T-- >0) {
            map = new int[9][9];
            
            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 9; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            System.out.printf("Case %d: %s\n",t++,solve() ? "CORRECT" : "INCORRECT");
            
            if(T != 0)
            br.readLine();
        }
    }
    
    static boolean solve() {
        for (int i = 0; i < 9; i++) {
            visited = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if(visited[map[i][j]])
                    return false;
                
                visited[map[i][j]] = true;
            }
            
            visited = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if(visited[map[j][i]])
                    return false;
                
                visited[map[j][i]] = true;
            }
        }
        
        for (int i = 0; i < 9; i++) {
            visited = new boolean[10];
            for (int j = dx[i]; j <dx[i]+3 ; j++) {
                for (int k = dy[i]; k < dy[i]+3; k++) {
                    if(visited[map[j][k]]) 
                        return false;
                        
                    visited[map[j][k]] = true;
                }
            }
        }
    
        return true;
    }
    
}