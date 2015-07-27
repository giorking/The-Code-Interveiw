class Solution {
public:
    int countJumps(int n) {
        if (n <= 1) return 1;
        int *fib = new int[n + 1];
        fib[0] = fib[1] = 1;
        for (int i = 2; i <= n; i ++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        int temp = fib[n];
        delete []fib;
        return temp;
    }
};