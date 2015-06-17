#include <vector>
#include <algorithm>

class Solution {
public:
    int getShortestSequenceLength(const vector<int> &a) {
        vector<int> vec(a.begin(), a.end());
        sort(vec.begin(), vec.end());
        int left = -1, right = vec.size();
        for (int i = 0; i < vec.size(); i ++) {
            if (vec[i] != a[i]) {
                left = i;
                break;
            }
        }
        for (int i = vec.size() - 1; i >= 0; i --) {
            if (vec[i] != a[i]) {
                right = i;
                break;
            }
        }
        if (left == -1 || right == vec.size()) return 0;
        else return right - left + 1;
    }
};
/**************************************************************
    Problem: 29
    User: iFighting
    Language: C++
    Result: Accepted
    Time:62 ms
    Memory:5960 kb
****************************************************************/