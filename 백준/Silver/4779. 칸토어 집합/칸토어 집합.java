import java.io.*;
import java.util.*;

public class Main {
    public static char[] arr;

    public static void rec(int start, int size) {
        if (size == 1) {
            return;
        }

        int newSize = size / 3;
        for (int i = start + newSize; i < start + 2 * newSize; i++) {
            arr[i] = ' ';
        }

        rec(start, newSize);
        rec(start + 2 * newSize, newSize);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;

        while ((str = br.readLine()) != null) {
            int num = Integer.parseInt(str);
            arr = new char[(int) Math.pow(3, num)];
            Arrays.fill(arr, '-');

            rec(0, arr.length);
            System.out.println(new String(arr));
        }
    }
}
