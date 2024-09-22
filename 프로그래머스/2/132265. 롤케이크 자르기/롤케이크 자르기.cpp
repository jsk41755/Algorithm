#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> m;
    map<int, int> s;
    
    for(auto a : topping){
        m[a]++;
    }
    
    for(auto a : topping){
        s[a]++;
        m[a]--;
        
        if(m[a] <= 0) m.erase(a);
        
        if(m.size() == s.size()) answer++;
    }
    
    
    return answer;
}