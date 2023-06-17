import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int hour = Integer.parseInt(st.nextToken());
		int minute = Integer.parseInt(st.nextToken());
		
		if(minute< 45) {
			minute = minute + 60 - 45;
			if(hour == 0) {
				hour = 24;
			}
			hour --;
		} else {
			minute -= 45;
		}
		
		System.out.print(hour + " " + minute);
		
	}

}
