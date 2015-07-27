class Solution {
public:
	int lastDigit(int n) {
        int n2 = 0, n5 = 0, nd = 0, res = 1;
        for (int i = 1; i <= n; i ++) {
            int j = i;
            while (j % 5 == 0) {
                j = j / 5;
                n5 ++;
            }
            while (j % 2 == 0) {
                n2 ++;
                j = j / 2;
            }
            res = (res * (j % 10)) % 10;
        }
        nd = n2 - n5;
        for (int i = 0; i < nd; i ++) {
            res = (res * 2) % 10;
        }
        return res;
	}
};
