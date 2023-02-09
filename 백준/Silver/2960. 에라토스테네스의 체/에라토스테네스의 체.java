import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static boolean[] isPrime = new boolean[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());

        int K = Integer.parseInt(st.nextToken());



        int cnt = 0;


        for(int i=2; i<=N; i++){
            for(int j=i; j<=N; j+=i) {
                if (isPrime[j] == false) {
                    cnt++;
                    isPrime[j] = true;
                }

                if (cnt == K) {
                    System.out.println(j);
                    return;
                }
            }
        }
    }
}
