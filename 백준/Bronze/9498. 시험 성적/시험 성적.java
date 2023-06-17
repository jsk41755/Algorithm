import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		
		if(num >= 90 && num <=100) {
			System.out.print('A');
		} else if(num >= 80 && num <= 89) {
			System.out.print('B');
		} else if(num >= 70 && num <= 79) {
			System.out.print('C');
		} else if(num >= 60 && num <= 69) {
			System.out.print('D');
		} else {
			System.out.print('F');
		}
		
	}

}
