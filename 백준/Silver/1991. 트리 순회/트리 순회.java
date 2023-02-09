import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n;
    static int child[][] = new int[27][3];

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(bf.readLine());

        char a, b, c;

        for(int i=1; i<=n; i++){
            String tmp = bf.readLine();
            a = tmp.charAt(0);
            b = tmp.charAt(2);
            c = tmp.charAt(4);
            if(b != '.') child[a-'A'+1][0] = b-'A'+1;
            if(c != '.') child[a-'A'+1][1] = c-'A'+1;
        }

        preorder(1);
        System.out.print("\n");
        inorder(1);
        System.out.print("\n");
        postorder(1);

    }

    private static void postorder(int i) {
        if(i == 0) return;
        postorder(child[i][0]);
        postorder(child[i][1]);
        System.out.print((char)('A'+i-1));
    }

    private static void inorder(int i) {
        if(i == 0) return;
        inorder(child[i][0]);
        System.out.print((char)('A'+i-1));
        inorder(child[i][1]);
    }

    private static void preorder(int i) {
        if(i == 0) return;
        System.out.print((char)('A'+i-1));
        preorder(child[i][0]);
        preorder(child[i][1]);
    }
}
