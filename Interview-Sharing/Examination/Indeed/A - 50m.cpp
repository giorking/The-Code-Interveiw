#include <cstdio>

int main() {
    int d = 50, s;
    scanf("%d", &s);
    if (d % s == 0) printf("%d\n", d / s);
    else {
        double v = d * 1.0 / s;
        printf("%.10lf\n", v);
    }
}