import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        long[] A = new long[n];
        A[0] = 1;
        if(n>1){
            A[1] = 1;
        }
        

        for(int i=2; i<n; i++){
            A[i] = A[i-1] + A[i-2];
        }
        System.out.println(A[n-1]);

    }
}