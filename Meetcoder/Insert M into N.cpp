class Solution {
public:
    int updateBits(int n, int m , int i, int j) {
        if (j - i == 31) return m;
        int  res = (1 << (j-i+1)) - 1;
        res = res << i;
        res = ~res;
        res = res & n;
        return res | (m << i);
    }
};
/**************************************************************
    Problem: 23
    User: iFighting
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1692 kb
****************************************************************/