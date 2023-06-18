import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(br.readLine());
		String str[] = new String[count];
		
		for(int i=0; i<count; i++) {
			str[i] = br.readLine();
		}
		
		Arrays.sort(str, new Comparator<String>() {
			public int compare(String s1, String s2) {
				// 단어 길이가 같을 경우 
				if (s1.length() == s2.length()) {
					return s1.compareTo(s2);
				} 
				// 그 외의 경우 
				else {
					return s1.length() - s2.length();
				}
			}
		});
		
		StringBuilder sb = new StringBuilder();
		 
		sb.append(str[0]).append('\n');
		
		for (int i = 1; i < count; i++) {
			// 중복되지 않는 단어만 출력
			if (!str[i].equals(str[i - 1])) {
				sb.append(str[i]).append('\n');
			}
		}
		System.out.println(sb);
	}
}