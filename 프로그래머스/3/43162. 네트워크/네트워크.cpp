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

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    arr.resize(n+1);
    
    for(int i=1; i<=n; i++){
        arr[i] = i;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && computers[i][j] == 1){
                Union(i+1, j+1);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        arr[i] = Find(arr[i]);    
    }
    
    
    
    sort(arr.begin(), arr.end());
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    
    for(int i=1; i<arr.size(); i++){
        answer++;
    }
    
    return answer;
}