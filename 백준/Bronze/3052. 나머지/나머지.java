import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int arr1[] = new int [42];
		int arr2[] = new int [10];
		
		for(int i=0; i<10; i++) {
			arr2[i] = Integer.parseInt(br.readLine());
			int ans = arr2[i]%42;
			if(ans != -1) {
				arr1[ans]++;
			}
			
		}
		int cnt = 0;
		for(int i=0; i<42; i++) {
			if(arr1[i] != 0) {
				cnt++;
			}
		}
		System.out.print(cnt);
	
	}

}
