#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int col = (brown - 2) / 2 - 2;
    int row = 1;
    
    int sol = 0;
    
    while(sol != yellow){
        sol = col * row;
        
        if(sol != yellow){
            col--;
            row++;
        }
    }
    
    answer.push_back(col+2);
    answer.push_back(row+2);
    
    return answer;
}