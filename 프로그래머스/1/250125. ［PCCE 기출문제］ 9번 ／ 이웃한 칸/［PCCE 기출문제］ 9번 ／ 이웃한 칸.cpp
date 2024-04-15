#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string currentCol = board[h][w];
    
    for(int i=0; i<4; i++){
        int nw = w + dx[i];
        int nh = h + dy[i];
        
        if(nw >= 0 && nw < board.size() && nh >= 0 && nh < board.size()){
            if(currentCol == board[nh][nw]){
                answer++;
            }
        }
    }
    
    
    return answer;
}