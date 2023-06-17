import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int i = Integer.parseInt(br.readLine());
		
		for(int k=1; k<=i; k++) {
			for(int j=1; j<=k; j++) {
				System.out.print("*");
			}
			System.out.println("");
		}
	}

}
