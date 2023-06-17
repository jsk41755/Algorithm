import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		double sol = 0;
		double i = Double.parseDouble(st.nextToken());
		double j = Double.parseDouble(st.nextToken());
		
		sol = i/ j;
		
		System.out.println(sol);

	}

}
