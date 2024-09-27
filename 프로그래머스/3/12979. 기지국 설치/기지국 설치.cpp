#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int loc = 1;
    int idx = 0;
    
    while(loc <= n){
        if(stations[idx]-w <= loc && idx < stations.size()){
            loc = stations[idx]+w+1;
            idx++;
        } else {
            loc += 2*w + 1;
            answer++;
        }
    }

    return answer;
}