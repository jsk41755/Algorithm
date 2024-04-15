#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int lastAttack = attacks[attacks.size()-1][0];
    int currentHealth = health;
    int bandageCnt = 0;
    int time = 0;
    
    for(int i=1; i<=lastAttack; i++){
        int nowHealth = currentHealth;
        
        for(int j=0; j<attacks.size(); j++){
            if(attacks[j][0] == i){
                currentHealth -= attacks[j][1];
                bandageCnt = 0;
                break;
            }
        }
        
        if(currentHealth <= 0){
            return -1;
        }
        
        if(nowHealth != currentHealth) continue;
        
        if(currentHealth < health){
            currentHealth += bandage[1];
            bandageCnt++;
        }
        
        if(bandageCnt == bandage[0]){
            currentHealth += bandage[2];
            bandageCnt = 0;
        }
        
        
        if(currentHealth > health){
            currentHealth = health;
        }
    }
    
    answer = currentHealth;
    
    return answer;
}