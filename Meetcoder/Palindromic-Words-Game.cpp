#include <string>

class Solution {
public:
	int minimumOperations(string &s) {
        int left = 0, right = s.size() - 1, res = 0;
        while (left < right) {
            if (s[left] != s[right]) {
                int temp = s[left] - s[right];
                if (temp < 0) temp = -temp;
                res += temp;
            }
            left ++;
            right --;
        }
        return res;
	}
};