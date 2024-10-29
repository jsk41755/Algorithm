import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());

        ArrayDeque<Integer> stack = new ArrayDeque<>();
        st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        int[] answer = new int[N];
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=N-1; i>=0; i--){
            while(!stack.isEmpty() && arr[stack.peek()] <= arr[i]){
                int top = stack.pop();
                answer[top] = i + 1;
            }

            stack.push(i);
        }

        for(int i=0; i<N; i++){
            System.out.print(answer[i] + " ");
        }

        return;
    }
}
