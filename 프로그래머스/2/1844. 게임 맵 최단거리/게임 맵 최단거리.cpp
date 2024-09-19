#include<vector>
#include<queue>

using namespace std;

bool isVisit[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101];

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    q.push({0,0});
    arr[0][0] = 1;
    isVisit[0][0] = true;
    
    while(!q.empty()){
        int ax = q.front().second;
        int ay = q.front().first;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = ax + dx[i];
            int ny = ay + dy[i];
            
            if(ny >= 0 && ny < maps.size() && nx >= 0 && nx < maps[0].size()){
                if(!isVisit[ny][nx] && maps[ny][nx] == 1){
                    q.push({ny, nx});
                    isVisit[ny][nx] = true;
                    arr[ny][nx] = arr[ay][ax] + 1;
                }
            }
        }
    }
    
    if(arr[maps.size()-1][maps[0].size()-1] == 0) answer = -1;
    else answer = arr[maps.size()-1][maps[0].size()-1];
    
    return answer;
}