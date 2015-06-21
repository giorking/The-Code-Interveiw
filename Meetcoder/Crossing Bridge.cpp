#include <algorithm>

class Solution {
public:
	int helper(vector<int> &v, int n) {
		if (n < 3) return v[n - 1];
		else if (n == 3) return v[0] + v[1] + v[2];
		int temp1 = v[n - 1] + v[0] + v[n - 2] + v[0];
		int temp2 = v[1] + v[0] + v[n-1] + v[1];
		return temp1 < temp2 ? temp1 + helper(v, n - 2) : temp2 + helper(v, n - 2);
	}
    int bridge(vector<int> &v) {
    	sort(v.begin(), v.end());
    	return helper(v, v.size());
    }
};