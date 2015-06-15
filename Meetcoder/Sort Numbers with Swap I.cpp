/**************************************************************
	Problem: 35
	User: iFighting
	Language: C++
	Result: Accepted
	Time:26 ms
	Memory:25024 kb
****************************************************************/


class Solution {
public:
	int sortWithSwap(vector<int> &a) {
		int res = 0;
		for (int i = 0; i < a.size(); i ++) {
			while (a[i] != i) {
				res ++;
				int temp = a[a[i]];
				a[a[i]] = a[i];
				a[i] = temp;
			}
		}
		return res;
	}
};

