#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int arr[101][101];
bool isVisit[101][101];

pair<int, int> st;
pair<int, int> en;
pair<int, int> le;

int solution(vector<string> maps) {
    int answer = 0;
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] == 'S'){
                st.first = i;
                st.second = j;
            } else if(maps[i][j] == 'X'){
                arr[i][j] = -1;
            } else if(maps[i][j] == 'L'){
                le.first = i;
                le.second = j;
            } else if(maps[i][j] == 'E'){
                en.first = i;
                en.second = j;
            }
        }
    }
    
    q.push({st.first, st.second});
    isVisit[st.first][st.second] = true;
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int ax = x + dx[i];
            int ay = y + dy[i];
            
            if(ax >= 0 && ax < maps[0].size() && ay >= 0 && ay < maps.size()){
                if(!isVisit[ay][ax] && arr[ay][ax] != -1){
                    isVisit[ay][ax] = true;
                    arr[ay][ax] = arr[y][x] + 1;
                    q.push({ay, ax});
                }
            }
        }
    }
    
    answer += arr[le.first][le.second];
    
    if(answer == 0) return -1; 
    
    fill(&arr[0][0], &arr[0][0] + 101 * 101, 0);
    fill(&isVisit[0][0], &isVisit[0][0] + 101 * 101, false);
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] == 'S'){
                st.first = i;
                st.second = j;
            } else if(maps[i][j] == 'X'){
                arr[i][j] = -1;
            } else if(maps[i][j] == 'L'){
                le.first = i;
                le.second = j;
            } else if(maps[i][j] == 'E'){
                en.first = i;
                en.second = j;
            }
        }
    }
    
    q.push({le.first, le.second});
    isVisit[le.first][le.second] = true;
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int ax = x + dx[i];
            int ay = y + dy[i];
            
            if(ax >= 0 && ax < maps[0].size() && ay >= 0 && ay < maps.size()){
                if(!isVisit[ay][ax] && arr[ay][ax] != -1){
                    isVisit[ay][ax] = true;
                    arr[ay][ax] = arr[y][x] + 1;
                    q.push({ay, ax});
                }
            }
        }
    }
    
    answer += arr[en.first][en.second];
    
    if(arr[en.first][en.second] == 0) return -1; 
    
    return answer;
}