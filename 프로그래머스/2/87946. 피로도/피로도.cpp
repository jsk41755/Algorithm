#include <string>
#include <vector>

using namespace std;

bool isVisit[5001];
int dungeon;
int answer = -1;
vector<vector<int>> Dungeons;

void back(int k, int cnt){
    
    for(int i=0; i<dungeon; i++){
        if(isVisit[i]) continue;
        
        if(k >= Dungeons[i][0]){
            isVisit[i] = true;
            back(k-Dungeons[i][1], cnt+1);
            answer = max(answer, cnt+1);
            isVisit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dungeon = dungeons.size();
    Dungeons = dungeons;
    
    back(k, 0);
    
    return answer;
}