import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		
		for(int k = 0; k < num; k++) {
			String a = br.readLine();
			int cnt = 0;
			int ans = 0;
			for(int i=0; i<a.length(); i++) {
				if(a.charAt(i) == 'O') {
					cnt ++;
					ans += cnt;
				} else{
					cnt = 0;
				}
			}
			
			System.out.println(ans);
		}
		
	}

}
