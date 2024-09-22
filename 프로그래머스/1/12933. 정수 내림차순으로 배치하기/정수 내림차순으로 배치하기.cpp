#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool tmp(long long a, long long b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    
    vector<long long> v;
    
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), tmp);
    
    for(long long tmp : v){
        answer *= 10;
        answer += tmp;
    }
    
    return answer;
}