class Solution {
public:
    long long merge(int start, int mid, int end, vector<int> &a, vector<int> &b) {
        long long cnt = 0;
        int i = start, j = mid + 1, k = start;
        while (i <= mid && j <= end) {
            if (a[i] > a[j]) {
                cnt += (end - j + 1);
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }
        while (i <= mid) {
            b[k++] = a[i++];
        }
        while (j <= end) {
            b[k++] = a[j++];
        }
        for (int i = start; i <= end; i ++) {
            a[i] = b[i];
        }
        return cnt;
    }
    long long inversePairs(int start, int end, vector<int> &a, vector<int> &b) {
        long long cnt = 0;
        if (start < end) {
            int mid = (start + end) / 2;
            cnt += inversePairs(start, mid, a, b);
            cnt += inversePairs(mid + 1, end, a, b);
            cnt += merge(start, mid, end, a, b);
        }
        return cnt;
    }
    long long sortWithSwap(vector<int> &a) {
        int len = a.size();
        vector<int> vec(len);
        long long res = inversePairs(0, len - 1, a, vec);
        return res;
    }
};
/**************************************************************
    Problem: 37
    User: iFighting
    Language: C++
    Result: Accepted
    Time:68 ms
    Memory:25024 kb
****************************************************************/