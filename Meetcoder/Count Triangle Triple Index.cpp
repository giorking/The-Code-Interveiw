#include <vector>

class Solution {
public:
	int countTriangleTripleIndex(vector<int> &A) {
        sort(A.begin(), A.end());
        int num = 0;
        for (int i = A.size() - 1; i - 2 >= 0; i --) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (A[left] + A[right] <= A[i]) left ++;
                else {
                    num += right - left;
                    right --;
                }
            }
        }
        return num;
	}
};