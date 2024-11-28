#include <string>
#include <vector>

using namespace std;

bool possible(int mid, vector<int> diffs, vector<int> times, long long limit){
    long long cur_t = 0;
    long long prev_t = 0;
    
    for(int i=0; i<diffs.size(); i++){
        if(mid >= diffs[i]){
            cur_t += times[i];
        } else {
            long long repeat = diffs[i] - mid;
            
            cur_t += times[i] + repeat * (times[i] + prev_t);
        }
        prev_t = times[i];
        if(limit < cur_t) return false;
    }
    return true;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1987654321;
    
    int l=1, r=100001;
    
    while(l<=r){
        int mid = (l+r) / 2;
        
        if(possible(mid, diffs, times, limit)){
            r = mid - 1;
            answer = min(answer, mid);
        } else {
            l = mid + 1;
        }
    }
    
    return answer;
}