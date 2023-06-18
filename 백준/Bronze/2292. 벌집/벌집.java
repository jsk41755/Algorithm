import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 
		int num = Integer.parseInt(br.readLine());
		int search = 1;
		int cnt = 1;
		while(true) {
			if(num > search) {
				search = search + cnt *6;
				cnt++;
			} else {
				break;
			}
		}
		
		System.out.print(cnt);
	}
 
}