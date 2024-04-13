#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=0; j<lost.size(); j++){
            if(reserve[i] == lost[j]) {
                lost[j] = -999;
                reserve[i] = -9999;
                break;
            }
        }
    }
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=0; j<lost.size(); j++){
            if(reserve[i] == lost[j] || reserve[i]-1 == lost[j] || reserve[i]+1 == lost[j]) {
                lost[j] = -999;
                break;
            }
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        if(lost[i] !=-999){
            n -= 1;
        }
    }
    
    answer = n;
    
    return answer;
}