#include <stdio.h>
int d[11];
int main() {
    d[0] = 1;
    for (int i = 1; i <= 10; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}