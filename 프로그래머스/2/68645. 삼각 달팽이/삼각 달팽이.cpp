#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n,0));
    int i=0, j=0, num = 1;
    while (true) {
        bool endFlag = true;
        while (i+1 < n && board[i+1][j] == 0) {
            board[i++][j] = num++;
            endFlag = false;
        }
        if (endFlag) break ;
        while (j+1 < n && board[i][j+1] == 0) {
            board[i][j++] = num++;
            endFlag = true;
        }
        if (!endFlag) break ;
        while (i-1 > 0 && j-1 > 0 && board[i-1][j-1] == 0) {
            board[i--][j--] = num++;
            endFlag = false;
        }
        if (endFlag) break ;
    }
    board[i][j] = num;
    
    for(auto col : board)
        for (auto num : col)
            if (num) answer.push_back(num);
    
    return answer;
}