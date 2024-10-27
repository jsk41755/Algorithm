import java.util.*;

class Solution {
    public int[] solution(String msg) {
        
        ArrayList<Integer> list = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<26; i++){
            map.put(Character.toString('A'+i), i+1);
        }
        
        String Cur = "";
        int cnt = 27;
        
        for(int i = 0; i< msg.length(); i++){
            Cur += msg.charAt(i);
            
            if(!map.containsKey(Cur)){
                map.put(Cur, cnt++);
                Cur = Cur.substring(0, Cur.length()-1);
                list.add(map.get(Cur));
                Cur = "";
                i--;
            }
        }
        list.add(map.get(Cur));
        
        int[] answer = new int[list.size()];
        
        for(int i=0; i<list.size(); i++){
            //System.out.print(list.get(i) + " ");
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}