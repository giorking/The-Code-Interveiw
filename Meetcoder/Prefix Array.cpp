#include <vector>
#include <unordered_set>

class Solution {
public:
	int leastPrefix(vector<int> &A) {
        unordered_set<int> hash, cur;
        for (int i = 0; i < A.size(); i ++) {
            if (hash.find(A[i]) == hash.end()) hash.insert(A[i]);
        }
        int len = hash.size(), cnt = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (cur.find(A[i]) == cur.end()) {
                cur.insert(A[i]);
                cnt ++;
            }
            if (cnt == len) return i;
        }
	}
};