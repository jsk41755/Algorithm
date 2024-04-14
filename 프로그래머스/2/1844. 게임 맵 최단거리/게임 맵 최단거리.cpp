#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int v[101][101] = {0,};
int ans = 99999999;

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isCheck[101][101] = {false,};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    q.push({0,0});
    v[0][0] = 1;
    isCheck[0][0] = true;
    
    while(!q.empty()){
        int ay = q.front().first;
        int ax = q.front().second;
        
        q.pop();
        
        
        for(int i=0; i<4; i++){
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            
            if(nx >= 0 && nx < maps[0].size() && ny >= 0 && ny < maps.size()){
                if(isCheck[ny][nx]) continue;
                
                if(maps[ny][nx] != 0){
                    isCheck[ny][nx] = true;
                    q.push({ny, nx});
                    v[ny][nx] = v[ay][ax] + 1;
                }
            }
        }
    }
    
    if(v[maps.size()-1][maps[0].size()-1] == 0){
        answer = -1;
    } else {
        answer = v[maps.size()-1][maps[0].size()-1];
    }
    
    return answer;
}