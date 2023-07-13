import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int num[] = new int[31];
	static int sol = 0;
	
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int n = Integer.parseInt(br.readLine());
    	
    	num[0] = 1;
    	num[2] = 3;
    	
    	for(int i=2; i<=n; i+=2){
    		num[i] = num[i-2]*3;
            for(int j=i-4; j>=0; j-=2){
            	num[i] += num[j]*2;
            }
        }
    	
    	System.out.println(num[n]);
    }


}
