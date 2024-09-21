#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<pair<int, int>> adj[2005];
    const int INF = 1e9+10;
    int d[2005];

    fill(d, d+N+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[1] = 0;
    
    for(int i=0; i<road.size(); i++){
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    pq.push({d[1], 1});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.first] <= d[cur.second] + nxt.second) continue;
            d[nxt.first] = d[cur.second] + nxt.second;
            pq.push({d[nxt.first], nxt.first});
        }

    }
    
    for(int i=1; i<=N; i++){
        if(d[i] <= K) answer ++;
    }
    
    return answer;
}