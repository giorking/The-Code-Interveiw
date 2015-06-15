class Solution {
public:
    long long countTrailingZeros(long long n) {
        long long num = 0;
        while (n != 0) {
            num += n / 5;
            n = n / 5;
        }
        return num;
	}
	long long findM(long long n) {
        long long left = 0, right = 9223372036854775807, mid, res = right;
        while (left <= right) {
            mid = left + (right - left) / 2;
            long long temp = countTrailingZeros(mid);
            if (temp >= n) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
	}
};