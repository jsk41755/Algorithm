import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int[] arr = new int[26];
		String s = br.readLine();
		
		for(int i =0; i<s.length(); i++) {
			if('a' <= s.charAt(i) && s.charAt(i) <= 'z') {
				arr[s.charAt(i) - 97]++;
			} else {
				arr[s.charAt(i) - 65]++;
			}
		}
		
		int max = -1;
		char ch = '?';
		for(int i = 0; i<26; i++) {
			if(arr[i] > max) {
				max = arr[i];
				ch = (char) (i+65);
			}
			else if(arr[i] == max){
				ch = '?';
			}
		}
		
		System.out.print(ch);
	}

}
