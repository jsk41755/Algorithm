#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int n = 101;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> test;
    
    for(int i=0; i<progresses.size(); i++){
        int pro = 100-progresses[i];
        int num = 0;
        while(pro > 0){
            pro -= speeds[i];
            num++;
        }
        test.push_back(num);
    }
    
    for(int i=0; i<progresses.size(); i++){
        for(int j=i+1; j < progresses.size(); j++){
            if(test[i] > test[j]){
                test[j] = test[i];
            } else {
                break;
            }
        }
    }
    
    answer;
    queue<int> q;
    
    for(int i=0; i<test.size(); i++){
        q.push(test[i]);
    }
    
    int cnt = 0;
    vector<int> ans (progresses.size(), 0);
    
    int num = q.front();
    
    for(int i=0; i<test.size(); i++){
        if(num == test[i]){
            ans[cnt]++;
            q.pop();
        } else{
            cnt++;
            num = q.front();
            q.pop();
            ans[cnt]++;
        }
    }
    
    for(int i=0; i<cnt+1; i++){
        cout << ans[i] << " ";
        answer.push_back(ans[i]);
    }
    
    return answer;
}