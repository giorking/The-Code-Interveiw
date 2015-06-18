#include <cmath>

class Solution {
public:
    long long gcd(long long x, long long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
	long long countLatticePoints(long long x1, long long y1, long long x2, long long y2) {
        return gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
    }
};