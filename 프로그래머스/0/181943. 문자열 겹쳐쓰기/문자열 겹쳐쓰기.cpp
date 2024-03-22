#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    int start = s;
    
    for(int i=0; i<overwrite_string.length(); i++){
        my_string[s] = overwrite_string[i];
        s++;
    }
    
    answer = my_string;
    
    return answer;
}