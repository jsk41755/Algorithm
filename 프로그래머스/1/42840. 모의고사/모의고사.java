import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        
        int[] a = {1,2,3,4,5};
        int[] b = {2,1,2,3,2,4,2,5};
        int[] c = {3,3,1,1,2,2,4,4,5,5};
        
        int aa = 0, bb = 0, cc= 0;
        int cnt = 0;
        for(int i=0; i<answers.length; i++){
            if(a[i%a.length] == answers[i]) aa++;
            if(b[i%b.length] == answers[i]) bb++;
            if(c[i%c.length] == answers[i]) cc++;
        }
        
        cnt = Math.max(cnt, aa);
        cnt = Math.max(cnt, bb);
        cnt = Math.max(cnt, cc);
        System.out.println(cnt);
        
        
        ArrayList<Integer> list = new ArrayList<>();
        
        if(cnt == aa){
            list.add(1);
        }
        
        if(cnt == bb){
            list.add(2);
        }
        
        if(cnt == cc){
            list.add(3);
        }
        
        
        int[] answer = new int[list.size()];
        
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}