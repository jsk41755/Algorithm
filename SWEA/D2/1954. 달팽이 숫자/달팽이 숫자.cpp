/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdio>

using namespace std;

int i, j;

int arr[10][10];
int cnt = 1;

int num = 0;

void right() {
    if (i >= 0 && i < num && j >= 0 && j < num) {
        if (arr[i][j] == 0) {
            arr[i][j] = cnt++;
            j++;
            right();
        }
    }
}

void bottom() {
    if (i >= 0 && i < num && j >= 0 && j < num) {
        if (arr[i][j] == 0) {
            arr[i][j] = cnt++;
            i++;
            bottom();
        }
    }
}

void left() {
    if (i >= 0 && i < num && j >= 0 && j < num) {
        if (arr[i][j] == 0) {
            arr[i][j] = cnt++;
            j--;
            left();
        }
    }
}

void top() {
    if (i >= 0 && i < num && j >= 0 && j < num) {
        if (arr[i][j] == 0) {
            arr[i][j] = cnt++;
            i--;
            top();
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int test_case;
	int T;
    
    //freopen("input.txt", "r", stdin);    
    
    cin >> T;
    
	for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> num;
        cnt = 1;
        i = 0;
        j = 0;
        
        for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
        arr[i][j] = 0;
    }
}
        if(num == 1) {
            cout << "#" << test_case << "\n";
            cout << "1" << "\n";
            continue;
        }

        while (arr[i][j] == 0) {
            right();
            j--;
            i++;

            bottom();
            i--;
            j--;

            left();
            i--;
            j++;

            top();
            i++;
            j++;
        }

        cout << "#" << test_case << "\n";

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }

}
	return 0;
}