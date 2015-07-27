/**************************************************************
    Problem: 33
    User: iFighting
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:23428 kb
****************************************************************/

#include <vector>

class Solution {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int cur = m + n - 1, Ai = m - 1, Bi = n - 1;
        while (Ai >= 0 && Bi >= 0) {
            if (A[Ai] >= B[Bi]) {
                A[cur--] = A[Ai--];
            } else {
                A[cur--] = B[Bi--];
            }
        }
        while (Ai >= 0) {
            A[cur--] = A[Ai--];
        }
        while (Bi >= 0) {
            A[cur--] = B[Bi--];
        }
    }
};