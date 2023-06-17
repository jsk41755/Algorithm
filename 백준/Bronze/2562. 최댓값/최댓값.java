import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int arr[] = new int[9];
		
		int max = -1;
		int maxNum = -1;
		
		for(int i=0; i<9; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			if(arr[i] > max) {
				max = arr[i];
				maxNum = i;
			}
		}
		
		System.out.print(max + "\n" + (maxNum+1));
		
	}

}
