class Solution {
public:
	int countTrailingZeros(int n) {
        int num = 0;
        while (n != 0) {
            num += n / 5;
            n = n / 5;
        }
        return num;
	}
};