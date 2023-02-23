import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int num, ans, cnt = 0;
		int fir=0;
		int[] arr;
		
		num = Integer.parseInt(br.readLine());
		
		ans = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int sec = num-1;
		
		arr = new int[num];
		
		for(int i=0; i<num; i++) {
			arr[i] = Integer.parseInt(st.nextToken());	
		}
		
		Arrays.sort(arr);
		
		while(fir < sec) {
			if(arr[fir]+arr[sec] > ans) {
				sec--;
			}
			else if(arr[fir]+arr[sec] == ans) {
				cnt++;
				fir++;
				sec--;
			}
			else {
				fir++;
			}
		}
		
		
		System.out.print(cnt);
	}
}