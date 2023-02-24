import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int L, C;
	static char[] carr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		L = sc.nextInt();
		C = sc.nextInt();
		carr = new char[C];
		for (int i = 0; i < C; i++) {
			carr[i] = sc.next().charAt(0);
		}
		Arrays.sort(carr);
		comb(0, 0, "");
	}

	static void comb(int cnt, int s, String str) {
		if (cnt == L) {
			if (check(str)) {
				System.out.println(str);
			}
		}
		for (int i = s; i < C; i++) {
			comb(cnt + 1, i + 1, str + carr[i]);
		}
	}
	static boolean check(String str) {
		int a=0,b=0;
		for(int i=0;i<str.length();i++) {
			if(a>=1 && b>=2)
				return true;
			if(str.charAt(i)=='a'||str.charAt(i)=='e'||str.charAt(i)=='i'||str.charAt(i)=='o'||str.charAt(i)=='u')
				a++;
			else
				b++;
		}
		if(a>=1&&b>=2)
			return true;
		return false;
	}

}