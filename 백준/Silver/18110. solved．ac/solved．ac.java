import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		
		if(num == 0) {
			System.out.print(0);
			return;
		}
		
		int a[] = new int [num];
		
		for(int i=0; i<num; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(a);
		
		int up = (int) Math.round((double) (num *0.15));
		
		int sum = 0;
		int minus = num - (2*up);
		
		for(int i=up; i<(num-up); i++) {
			sum += a[i];
		}
		
		double douMin = (double)(minus);
		
		System.out.print(Math.round((double) (sum/douMin)));
		
	}
 
}