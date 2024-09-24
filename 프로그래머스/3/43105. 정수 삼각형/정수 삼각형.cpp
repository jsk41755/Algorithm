#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int a[501][501];
    int d[501][501];
    
    for(int i=0; i<triangle.size(); i++){
        for(int j=0; j<triangle[i].size(); j++){
            a[i+1][j+1] = triangle[i][j];
        }
    }
    
    for(int i=1; i<triangle.size()+1; i++){
        for(int j=1; j<triangle[i-1].size()+1; j++){
            d[i][j] = a[i][j] + max(d[i-1][j-1], d[i-1][j]);
        }
    }
    
    for(int i=1; i<triangle.size()+1; i++){
        answer = max(answer, d[triangle.size()][i]);
    }
    
    return answer;
}