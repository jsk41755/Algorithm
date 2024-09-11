#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    queue<string> cd1;
    queue<string> cd2;
    
    vector<string> ans;
    
    for(int i=0; i<cards1.size(); i++){
        cd1.push(cards1[i]);
    }
    
    for(int i=0; i<cards2.size(); i++){
        cd2.push(cards2[i]);
    }
    
    for(int i=0; i<goal.size(); i++){
        if(cd1.front() == goal[i]){
            ans.push_back(cd1.front());
            cd1.pop();
        } else if(cd2.front() == goal[i]){
            ans.push_back(cd2.front());
            cd2.pop();
        } else {
            answer = "No";
            return answer;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<goal.size(); i++){
        if(ans[i] == goal[i]){
            cnt++;
        }
    }
    
    if(cnt == goal.size()) answer = "Yes";
    else answer = "No";
    
    return answer;
}