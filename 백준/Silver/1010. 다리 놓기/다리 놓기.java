import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int T, N, K, sol;

    private static final int[][] dp = new int[31][31];

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(bf.readLine());

        for(int i = 0; i<T; i++){
            String temp[] = bf.readLine().split(" ");

            N = Integer.parseInt(temp[0]);

            K = Integer.parseInt(temp[1]);

            sol = factorial(K, N);

            System.out.println(sol);

            }

        }

    public static int factorial(int n, int k){
        if(dp[n][k] > 0) return dp[n][k];

        else if(n == k || k == 0) return dp[n][k] = 1;

        else{
            return dp[n][k] = factorial(n-1, k-1) + factorial(n-1, k);
        }
    }

}
