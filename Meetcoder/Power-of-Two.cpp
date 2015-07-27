class Solution {
public:
	bool isPowerOf2(int n) {
		long long cnt = n;
        return (cnt != 0) && ((cnt & (cnt - 1)) == 0);
    }
};