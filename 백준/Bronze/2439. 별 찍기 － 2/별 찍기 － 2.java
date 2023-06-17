import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int i = Integer.parseInt(br.readLine());
		int num = i;
		for(int k=1; k<=i; k++) {
			for(int j=num-1; j>0; j--) {
				System.out.print(" ");
			}
			for(int p=1; p<=k; p++) {
				System.out.print("*");
			}
			System.out.println("");
			num --;
		}
	}

}
