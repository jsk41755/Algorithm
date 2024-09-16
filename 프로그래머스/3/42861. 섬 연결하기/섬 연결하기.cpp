#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;

int Find(int i){
    if(arr[i] == i) return i;
    else return arr[i] = Find(arr[i]);
}

void Union(int a, int b){
    int aRoot = Find(a);
    int bRoot = Find(b);
    
    arr[aRoot] = bRoot;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
        return a[2] < b[2];
    });
    
    arr.resize(n+1);
    
    for(int i=0; i<n; i++){
        arr[i] = i;
    }
    
    int edges = 0;
    
    for(int i=0; i<costs.size(); i++){
        if(edges == n-1) break;
        
        if(Find(costs[i][0]) != Find(costs[i][1])){
            Union(costs[i][0], costs[i][1]);
            answer += costs[i][2];
            edges++;
        }
    }
    
    
    return answer;
}