#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i=0; i<my_string.length(); i++){
        if(my_string[i] > 96){
            char a = my_string[i];
            my_string[i] = a - 32;
        } else {
            char a = my_string[i];
            my_string[i] = a + 32;
        }
    }
    
    answer = my_string;
    
    return answer;
}