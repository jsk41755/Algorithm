import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		
		for(int i=0; i<num; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int count = Integer.parseInt(st.nextToken());
			String code = st.nextToken();
			
			for(int j=0; j<code.length(); j++) {
				for(int k=0; k<count; k++) {
					System.out.print(code.charAt(j));
				}
			}
			System.out.println();
		}
		
	}

}
