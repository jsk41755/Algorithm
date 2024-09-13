#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string, string> parent;
    for(int i=0; i<enroll.size(); i++){
        parent.insert({enroll[i], referral[i]});
    }
    
    map<string, int> total;
    
    for(int i=0; i<seller.size(); i++){
        string curName = seller[i];
        int money = amount[i] * 100;
        
        while(money > 0 && curName != "-"){
            total[curName] += money - (money/10);
            curName = parent[curName];
            money /= 10;
        }
    }
    
    for(int i=0; i<enroll.size(); i++){
        answer.push_back(total[enroll[i]]);
    }
    
    
    return answer;
}