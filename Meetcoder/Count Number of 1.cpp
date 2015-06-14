class Solution {
public:
	int count1(int x) {
        int res = 0;
        while (x) {
            x = x & (x - 1);
            res ++;
        }
        return res;
	}
};