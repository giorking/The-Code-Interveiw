#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int p, q;
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= p; i ++) {
        if (p % i == 0) {
            for (int j = 1; j <= q; j ++) {
                if (q % j == 0) {
                    printf("%d %d\n", i, j);
                }
            }
        }
    }
    return 0;
}