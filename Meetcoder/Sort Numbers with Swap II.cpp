class Solution {
public:
	int sortWithSwap(vector<int> &a) {
        int len = a.size(), index = 0, res = 0;
        for (int i = 0; i < len; i ++) {
            if (a[i] == 0 && i != 0) {
                res += 1;
                swap(a[0], a[i]);
                while (a[i] != i) {
                    res += 1;
                    swap(a[i], a[a[i]]);
                }
            }
        }
        for (int i = 0; i < len; i ++) {
            if (a[i] != i) {
                swap(a[0], a[i]);
                res += 1;
                while (a[0] != 0) {
                    swap(a[0], a[a[0]]);
                    res += 1;
                }
            }
        }
        return res;
	}
};