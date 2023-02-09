import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

        N = Integer.parseInt(st.nextToken());

        K = Integer.parseInt(st.nextToken());

        int sol, a, b;

        sol = factorial(N);

        a = factorial(N-K);

        b = factorial(K);

        System.out.println((sol/(a*b)));

    }

    public static int factorial(int factorial){
        if(factorial == 1 || factorial == 0) return 1;

        return factorial * factorial(factorial-1);
    }
}
