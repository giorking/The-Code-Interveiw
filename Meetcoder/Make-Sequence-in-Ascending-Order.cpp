class Solution {
public:
    int Binary_Search(const vector<int> &a, vector<int> &dp, int pos, int cnt) {
        int key = a[pos] - pos;
        if (key < 1) return 0;
        int start = 0, end = cnt - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == 0 && key < dp[mid] || mid > 0 && dp[mid - 1] <= key && dp[mid] > key) {
                dp[mid] = key;
                return 0;
            } else if (dp[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;    
            }
        }
        dp[cnt] = key;
        return 1;
    }
    int makeSequence(const vector<int> &a) {
        int len = a.size();
        vector<int> dp(len);
        int cnt = 0;
        for (int i = 0; i < len; i ++) {
            cnt += Binary_Search(a, dp, i, cnt);
        }
        return len - cnt;
    }
};
/**************************************************************
    Problem: 40
    User: iFighting
    Language: C++
    Result: Accepted
    Time:512 ms
    Memory:44912 kb
****************************************************************/