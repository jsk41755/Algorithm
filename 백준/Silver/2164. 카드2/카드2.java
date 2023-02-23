import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num;
		Queue<Integer> que = new LinkedList<>();
		
		num = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=num; i++) {
			que.add(i);	
		}
		
		
		while(que.size()!=1) {
			if(que.size()==2) {
				que.remove();
				break;
			}
			que.remove();
			que.add(que.poll());
		}
		
		
		System.out.print(que.peek());
	}
}