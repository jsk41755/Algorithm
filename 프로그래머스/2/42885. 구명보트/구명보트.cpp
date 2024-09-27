#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int i=0, j=people.size()-1;
    int cnt = 0;
    
    while(i<=j){
        if(people[i]+people[j] <= limit){
            i +=1;
        }
        
        j-=1;
        cnt++;
    }
    
    return cnt;
}