#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m;
    string tmp = "";
    for(int i=1; i<s.size()-1; i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){
            tmp += s[i];
            if(s[i+1] == '{' || s[i+1] == '}' || s[i+1] == ','){
                m[stoi(tmp)]++;
            }else {
                continue;
            }
        }
        tmp = "";
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto a: v){
        answer.push_back(a.first);
    }
    
    
    return answer;
}