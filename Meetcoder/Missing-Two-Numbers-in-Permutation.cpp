#include <vector>

class Solution {
public:
	vector<int> missing2Numbers(vector<int> &a) {
        int res = 0, len = a.size();
        for (int i = 0; i < a.size(); i ++) {
            res ^= a[i];
        }
        for (int i = 1; i <= len + 2; i ++) {
            res ^= i;
        }
        int cur = res & ~(res - 1);
        int x = 0, y = 0;
        for (int i = 0; i < a.size(); i ++) {
            if (cur & a[i]) x ^= a[i];
            else y ^= a[i];
        }
        for (int i = 1; i <= len + 2; i ++) {
            if (i & cur) x ^= i;
            else y ^= i;
        }
        vector<int> vec;
        vec.push_back(min(x, y));
        vec.push_back(max(x, y));
        return vec;
	}
};