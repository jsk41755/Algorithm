#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    pair<int, int> player = {0, 0};
    
    for(int i=0; i < keyinput.size(); i++){
        int x = player.first;
        int y = player.second;
        
        if(keyinput[i] == "left" && x-1 >= -board[0]/2){
            player.first -= 1;
        } else if(keyinput[i] == "right" && x+1 <= board[0]/2){
            player.first += 1;
        } else if(keyinput[i] == "down" && y-1 >= -board[1]/2){
            player.second -= 1;
        } else if(keyinput[i] == "up" && y+1 <= board[1] /2){
            player.second += 1;
        }
    }
    
    answer.push_back(player.first);
    answer.push_back(player.second);
    
    return answer;
}