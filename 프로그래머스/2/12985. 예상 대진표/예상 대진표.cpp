#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    for(answer; a!=b; answer++){
        a = (a+1) / 2;
        b = (b+1) / 2;
    }

    return answer;
}