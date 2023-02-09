import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	static int S,P,answer;
	static String DNA;
	static char[] dna = {'A','C','G','T'};
	static Map<Character, int[]> m= new HashMap<>(); 
	public static void main(String[] args) throws NumberFormatException, IOException {
		solve();
	}

	static void solve() throws NumberFormatException, IOException {
		input();
		solution();
		System.out.println(answer);
	}

	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());
		DNA = br.readLine();
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) {
			m.put(dna[i], new int[] {0, Integer.parseInt(st.nextToken())});
		}
	}
	static void solution() {
		
		for(int i=0;i<P;i++) {
			m.get(DNA.charAt(i))[0]++;
			
		}
		check();
		for(int i=P;i<S;i++) {
			m.get(DNA.charAt(i-P))[0] -= 1;
			m.get(DNA.charAt(i))[0] += 1;
			check();
		}
	}
	static void check() {
		for(int i=0;i<4;i++) {
			if(m.get(dna[i])[0]<m.get(dna[i])[1])
				return;
		}
		answer++;
	}

}