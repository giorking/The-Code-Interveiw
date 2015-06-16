class Solution {
public:
	long long xorSum(long long  x) {
        if(x % 2 == 1) {
            return (x % 4 == 1) ? 1 : 0;
        } else {
            return (x % 4 == 0) ? x : x+1;
        }
	}
};
