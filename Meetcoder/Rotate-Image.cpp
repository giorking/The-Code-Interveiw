#include <vector>

class Solution {
public:
	void rotate(vector<vector<int> >& matrix) {
        int len = matrix.size();
        if (len <= 1) return;
        for (int i = 0; i < len; i ++) {
            int left = 0, right = len - 1;
            while (left < right) {
                swap(matrix[left][i], matrix[right][i]);
                left ++;
                right --;
            }
        }
        for (int i = 0; i < len; i ++) {
            for (int j = i + 1; j < len; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
	}
};