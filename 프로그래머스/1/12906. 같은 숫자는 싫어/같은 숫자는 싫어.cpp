#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<int> q;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    q.push(arr[0]);
    
    for(int i=1; i<arr.size(); i++){
        if(q.back() != arr[i]){
            q.push(arr[i]);
        }
    }
    
    int n = q.size();
    
    for(int i=0; i<n; i++){
        answer.push_back(q.front());
        q.pop();
    }
    

    return answer;
}