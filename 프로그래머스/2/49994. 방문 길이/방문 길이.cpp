#include <string>
#include <iostream>
using namespace std;

bool isVisit[11][11][4];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int solution(string dirs) {
    int answer = 0;
    
    int x = 5;
    int y = 5;

    
    for(int i=0; i<dirs.size(); i++){
        int dir = 0;
        char a = dirs[i];
        if(a == 'L'){ // 방향 결정
            dir = 0;
        } else if(a == 'U'){
            dir = 1;
        } else if(a == 'R'){
            dir = 2;
        } else {
            dir = 3;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;
        int countdir = (dir + 2) % 4; 
        if(!isVisit[x][y][dir] && !isVisit[nx][ny][countdir]){
            isVisit[x][y][dir] = true;
            isVisit[nx][ny][countdir] = true;
            answer++;
        }
        x = nx;
        y = ny;
    }
    
    return answer;
}