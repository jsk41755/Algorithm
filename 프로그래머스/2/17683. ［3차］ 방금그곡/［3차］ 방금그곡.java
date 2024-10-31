import java.util.*;

class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        
        m = m.replace("C#", "1");
        m = m.replace("D#", "2");
        m = m.replace("F#", "3");
        m = m.replace("G#", "4");
        m = m.replace("A#", "5");
        m = m.replace("B#", "6");
        
        int time = -1;
        
        for(int i=0; i<musicinfos.length; i++){
            String[] s = musicinfos[i].split(",");
            String[] hs = s[0].split(":");
            int sh = Integer.parseInt(hs[0]) * 60 + Integer.parseInt(hs[1]);
            
            String[] he = s[1].split(":");
            int eh = Integer.parseInt(he[0]) * 60 + Integer.parseInt(he[1]);
            
            s[3] = s[3].replace("C#", "1");
            s[3] = s[3].replace("D#", "2");
            s[3] = s[3].replace("F#", "3");
            s[3] = s[3].replace("G#", "4");
            s[3] = s[3].replace("A#", "5");
            s[3] = s[3].replace("B#", "6");
            
            String info = "";
            for(int j=0; j<eh-sh; j++){
                info += s[3].charAt(j % s[3].length());
            }
            
            if(info.contains(m)){
                if(time < eh-sh){
                    time = eh - sh;
                    answer = s[2];
                }
            }
        }
        
        if(time == -1){
            answer = "(None)";
        }
        
        return answer;
    }
}