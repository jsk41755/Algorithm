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
        int[] ans = new int[N];
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=0; i<N; i++){
            while(!stack.isEmpty() && arr[stack.peek()] <= arr[i]){
                stack.pop();
            }

            if(!stack.isEmpty()){
                int top = stack.peek();
                answer[i] = top + 1;
                ans[i] += stack.size();
            }
            stack.push(i);
        }

        while(!stack.isEmpty()){
            stack.pop();
        }

        for(int i=N-1; i>=0; i--){
            while(!stack.isEmpty() && arr[stack.peek()] <= arr[i]){
                stack.pop();
            }

            if (!stack.isEmpty()) {
                if (answer[i] == 0 || Math.abs(i - (answer[i] - 1)) > Math.abs(i - stack.peek())) {
                    answer[i] = stack.peek() + 1;
                }
                ans[i] += stack.size();
            }

            stack.push(i);
        }

        for(int i=0; i<N; i++){
            if(ans[i] == 0) {
                System.out.println(0);
            } else{
                System.out.print(ans[i] + " ");
                System.out.println(answer[i]);
            }
        }

        return;
    }
}
