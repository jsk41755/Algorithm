#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer (2, 0);
    
    string a = "";
    
    while(s != "1"){
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') cnt++;
        }
        
        string k = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') {
                answer[1]++;
                continue;
            }
            else k += '1';
        }
        
        int si = k.size();
        vector<char> v;
        while(si > 0){
            if(si % 2 == 0) v.push_back('0');
            else v.push_back('1');
            
            si /= 2;
        }
        s = "";
        reverse(v.begin(), v.end());
        
        for(int i=0; i<v.size(); i++){
            s += v[i];
        }
        answer[0]++;
    }
    
    return answer;
}