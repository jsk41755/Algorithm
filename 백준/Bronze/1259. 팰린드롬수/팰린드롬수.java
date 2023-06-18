import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String a = null;
		
		while(true) {
			a = br.readLine();
			
			if(a.equals("0")) {
				break;
			}
			
			boolean isOk = true;
			
			for (int i = 0; i < a.length()/2; i++) {
				if (a.charAt(i) != a.charAt(a.length() - 1 - i)) isOk = false;
			}
			
			if(isOk) {
				System.out.println("yes");
			} else {
				System.out.println("no");
			}
			
		}
	}
}