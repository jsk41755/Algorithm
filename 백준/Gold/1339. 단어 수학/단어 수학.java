import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static BufferedReader br;
    static int N;
    static String str;
    static int[] alpha;
    static int num, answer;

    public static void main(String[] args) throws NumberFormatException, IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        alpha = new int[26];

        for(int i = 0; i < N; i++) {
            str = br.readLine();
            for(int j = 0; j < str.length(); j++) {
                alpha[str.charAt(j) - 'A'] += (Math.pow(10, str.length() - j - 1));
            }
        }

        Arrays.sort(alpha);
        num = 9;

        for(int i = 25; i >= 0; i--) {
            if(alpha[i] == 0) {
                continue;
            }
            answer += (alpha[i] * num);
            num--;
        }

        System.out.println(answer);

    }

}