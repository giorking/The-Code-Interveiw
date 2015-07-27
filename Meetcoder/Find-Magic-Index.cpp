#include <vector>

class Solution {
public:
	int getMagicIndex(vector<int> &A) {
        int left = 0, right = A.size() - 1, mid;
        int index = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == mid) {
                index = mid;
                right = mid - 1;
            }
            else if(A[mid] > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
	}
};