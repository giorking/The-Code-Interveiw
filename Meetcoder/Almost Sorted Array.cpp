class Solution {
public:
    bool Swap_Sorted(vector<int> a, int left, int right) {
        if (left < right) swap(a[left], a[right]);
        for (int i = 0; i + 1 < a.size(); i ++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }
    bool Reverse_Sorted(vector<int> a, int left, int right) {
        int x = left, y = right;
        while (x < y) {
            swap(a[x], a[y]);
            x ++;
            y --;
        }
        for (int i = 0; i + 1 < a.size(); i ++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }
    bool isAlmostSorted(vector<int> &a) {
        if(a.size() <= 2) return true;
        int left = 0, right = a.size() - 1;
        for (int i = 0; i + 1 < a.size(); i ++) {
            if (a[i] > a[i+1]) {
                break;
            } else if (a[i] < a[i+1]) {
                left = i + 1;
            }
        }
        for (int i = a.size() - 1; i - 1 >= 0; i --) {
            if (a[i] < a[i-1]) {
                break;
            } else if(a[i] > a[i-1]) {
                right = i - 1;
            }
        }
        if (Swap_Sorted(a, left, right) || Reverse_Sorted(a, left, right)) return true;
        else return false;
    }
};
/**************************************************************
    Problem: 31
    User: iFighting
    Language: C++
    Result: Accepted
    Time:183 ms
    Memory:37400 kb
****************************************************************/