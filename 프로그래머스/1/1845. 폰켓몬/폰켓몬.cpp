#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int cnt = nums.size() / 2 ;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for(int i=0; i< nums.size(); i++){
        answer++;
    }
    
    if(cnt < answer){
        answer = cnt;
    }
    
    return answer;
}