#include <vector>
#include <algorithm>

class Solution {
public:
	int minimizeUnfairness(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        int minRes = 0x7fffffff;
        for (int i = 0; i + k - 1 < a.size(); i ++) {
            minRes = min(minRes, a[i + k - 1] - a[i]);
        }
        return minRes;
	}
};