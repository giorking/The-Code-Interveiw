class Solution {
public:
	int swapOddEvenBits(int x) {
        for (int i = 0; i <= 15; i ++) {
            int r1 = 1 << (i * 2);
            int r2 = 1 << (i * 2 + 1);
            int t1 = r1 & x;
            int t2 = r2 & x;
            t1 = t1 << 1;
            t2 = t2 >> 1;
            x = x & (~r1);
            x = x & (~r2);
            x = x | t1;
            x = x | t2;
        }
        return x;
    }
};