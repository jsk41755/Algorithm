#include <iostream>
#include <vector>
using namespace std;

vector<int> A[1001];
vector<bool> ans;

void dfs(int node) {
    ans[node] = true;
    for (int i = 0; i < A[node].size(); i++) {
        int next = A[node][i];
        if (ans[next] == false) {
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    ans.resize(N+1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        A[u].push_back(v);
        A[v].push_back(u);
    }

    int components = 0;
    
    for (int i = 1; i <= N; i++) {
        if (ans[i] == false) {
            dfs(i);
            components++;
        }
    }

    cout << components << "\n";
}

