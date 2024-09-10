#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> st;
    
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i] - 1;
        
        for (int j = 0; j < board.size(); j++) { // board 크기에 맞추어 동적 처리
            if (board[j][move] == 0) continue;
            else {
                if (!st.empty() && st.top() == board[j][move]) {
                    st.pop();
                    answer += 2;
                } else {
                    st.push(board[j][move]);
                }
                board[j][move] = 0; // 인형을 집어갔으므로 해당 자리를 0으로
                break; // 인형을 찾았으므로 다음 move로 이동
            }
        }
    }

    return answer;
}
