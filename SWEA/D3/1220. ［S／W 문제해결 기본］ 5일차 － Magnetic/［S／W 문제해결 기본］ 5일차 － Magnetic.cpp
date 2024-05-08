#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T = 0;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int arr[100] = { 0, };
        int sol = 0;
           
        int temp = 0;
        cin >> temp;

        int num = 0;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> num;

                if (num == 1) {
                    arr[j] = 1;
                }
                else if (num == 2) {
                    arr[j] -= 2;
                }

                if (arr[j] == -1) {
                    arr[j] = 0;
                    sol++;
                }
            }
        }


        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}