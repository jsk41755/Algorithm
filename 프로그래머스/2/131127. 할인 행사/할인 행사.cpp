#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> m;
    
    for(int i=0; i<want.size(); i++){
        m.insert({want[i], number[i]});
    }
    
    for(int i=0; i < discount.size()-9; i++){
        map<string, int> ms(m);
        bool able = true;
        
        for(int j=i; j<i+10; j++){
            ms[discount[j]]--;
        }
        
        for(auto c : ms) {
            if (c.second){
                able = false;
                break;
            }
        }
    
        if(able) answer++;
    }
    
    return answer;
}