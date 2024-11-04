import java.util.*;

class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int time = Integer.parseInt(pos.substring(0, 2)) * 60 + Integer.parseInt(pos.substring(3));
        int vi_time = Integer.parseInt(video_len.substring(0, 2)) * 60 + Integer.parseInt(video_len.substring(3));
        
        int op_time = Integer.parseInt(op_start.substring(0, 2)) * 60 + Integer.parseInt(op_start.substring(3));
        int en_time = Integer.parseInt(op_end.substring(0, 2)) * 60 + Integer.parseInt(op_end.substring(3));
        
        for(int i=0; i<commands.length; i++){
            if(op_time <= time && time <= en_time){
                time = en_time;
            }
            
            if(commands[i].equals("next")){
                time += 10;
                if(vi_time - time < 10) time = vi_time;
            } else if(commands[i].equals("prev")){
                time -= 10;
                if(time <= 0) time = 0;
            } 
            
            if(op_time <= time && time <= en_time){
                time = en_time;
            }
        }
        
        String hour = "";
        if(time / 60 <= 9){
            hour += '0';
        }
        hour += Integer.toString(time/60);
        answer += hour + ':';
        
        String min = "";
        if(time % 60 <= 9){
            min += '0';
        }
        min += Integer.toString(time%60);
        answer += min;
        
        return answer;
    }
}