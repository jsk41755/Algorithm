#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> v;
    int isCheck = 0;
    char a;
    for(int i=0; i<words.size(); i++){
        for(int j=0; j<v.size(); j++){            
            if(v[j] == words[i]){
                isCheck = i;
                break;
            }
        }
        
        if(i>0 && a != words[i][0]){
            isCheck = i;
        }
        
        a = words[i][words[i].size()-1];
        
        if(isCheck == 0){
            v.push_back(words[i]);
        } else {
            answer.push_back((isCheck%n) + 1);
            answer.push_back(isCheck/n + 1);
            return answer;
            break;
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}