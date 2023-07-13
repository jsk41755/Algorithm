import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int n = 0;
	static int sol = 0;
	static long num[] = new long[101];
	
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int tc = Integer.parseInt(br.readLine());
        
    	for(int i=0; i<tc; i++) {
    		n = Integer.parseInt(br.readLine());
    		sol = 0;
    		
    		num[0] = 1;
    		num[1] = 1;
    		num[2] = 1;
    		num[3] = 2;
    		
    		fibo(4);
    		
    		System.out.println(num[n-1]);
    	}
    }

	private static void fibo(int cnt) {
		if(cnt < n) {
			num[cnt] = num[cnt-2] + num[cnt-3];
			cnt++;
			fibo(cnt);
		}
		
	}

}
