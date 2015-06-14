class Solution {
public:
	long long aMultiplyb(int a,int b) {
        if (a == 0 || b == 0) return 0;
        long long res = 0, x = a, y = b;
        while (y != 0) {
            long long cur = 1, cnt = 0;
            while ((cur << 1) <= y) {
                cur = cur << 1;
                cnt ++;
            }
            res += (x << cnt);
            y = y - cur;
        }
        return res;
	}
};