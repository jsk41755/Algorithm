import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayDeque<Integer> que = new ArrayDeque<>();
        
        // 배열 크기를 10001로 설정
        int[] arr = new int[10001];
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr[a] = i + 1;
            arr[b] = i + 1;
        }

        for (int i = 1; i <= 10000; i++) { // 1부터 10000까지 확인
            if (arr[i] != 0) { // 초기화된 값만 큐에 추가
                que.addLast(arr[i]);
            }
        }

        int cnt = 1;

        while (cnt <= n) {
            if (cnt == n) {
                System.out.print(que.peekFirst());
                return;
            }
            cnt++;
            que.addLast(que.peekFirst());
            que.removeFirst();
        }
    }
}
