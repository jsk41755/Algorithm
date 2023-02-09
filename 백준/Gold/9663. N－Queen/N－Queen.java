import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int cnt,n;
    static int visit_y[] = new int[16];
    static int visit_l[] = new int[33];
    static int visit_r[] = new int[33];

    static void back(int x)
    {
        if(x==n+1)
        {
            cnt++;
            return;
        }

        for(int i=1;i<=n;i++)
        {
            if(visit_y[i]==0&&visit_l[x-i+n]==0&&visit_r[x+i]==0) {
                visit_y[i]=1;
                visit_l[x-i+n]=1;
                visit_r[x+i]=1;
                back(x+1);
                visit_y[i]=0;
                visit_l[x-i+n]=0;
                visit_r[x+i]=0;
            }
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        back(1);

        System.out.println(cnt);
    }

}