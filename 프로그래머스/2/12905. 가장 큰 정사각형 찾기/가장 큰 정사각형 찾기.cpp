#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int col = board[0].size();
    int row = board.size();

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(board[i][j] == 1){
                int up = board[i-1][j];
                int left = board[i][j-1];
                int upLeft = board[i-1][j-1];
                
                board[i][j] = min(up, min(left, upLeft)) + 1;
            }
        }
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            answer = max(answer, board[i][j]);
        }
    }

    return answer * answer;
}