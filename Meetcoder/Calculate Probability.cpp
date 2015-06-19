class Solution {
public:
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    vector<int> calculate(int a,int b,int c) {
        vector<int> res(2);
        res[0] = res[1] = 1;
        if (a == 0 || b == 0) return res;
        if (c == 0) {
            res[0] = res[1] = 0;
            return res;
        }
        if (a > b) swap(a, b);
        int x, y = a * b * 2;
        if (c <= a) {
            x = c * c;
        } else if (c <= b) {
            x = 2 * a * c - a * a;
        } else if (c <= a + b) {
            x = y - (a + b - c) * (a + b - c);
        } else {
            x = y;
        }
        int temp = gcd(x, y);
        res[0] = x / temp;
        res[1] = y / temp;
        return res;
    }
};
/**************************************************************
    Problem: 48
    User: iFighting
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:1696 kb
****************************************************************/