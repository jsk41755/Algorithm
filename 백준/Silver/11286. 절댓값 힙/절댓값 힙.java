import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num  = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> mnq = new PriorityQueue<>((o1,o2)->{
			int first_abs = Math.abs(o1);
			int second_abs = Math.abs(o2);
			
			if(first_abs == second_abs) {
				return o1 > o2 ? 1 : -1;
			}
			
			return first_abs - second_abs;
		});
		
		
		for(int i=0; i<num; i++) {
			int request = Integer.parseInt(br.readLine());
			if(request == 0) {
				if(mnq.isEmpty()) {
					System.out.println("0");
				}
				else {
					System.out.println(mnq.poll());
				}
			}
			else {
				mnq.add(request);
			}
		}
	
	}
}