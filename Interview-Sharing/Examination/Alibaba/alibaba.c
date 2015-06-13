#include <stdio.h>
void func() {
    static int b;
    printf("%d", b);
}
int main() {
    int a = 1, x = 2;
    a=x>1?5*x:(x=7);
    printf("%d %d", a, x);
}
