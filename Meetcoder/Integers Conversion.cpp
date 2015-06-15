class Solution {
public:
	int countConversions(int x,int y) {
        int res = x ^ y;
        if (res == 0) return 0;
        int num = 0;
        while (res != 0) {
            res = res & (res - 1);
            num ++;
        }
        return num;
	}
};