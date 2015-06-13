class Solution {
public:
	static bool cmp(int x, int y) {
		return x > y;
	}
	bool canPair(vector<int> &a, vector<int> &b, int k) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), cmp);
		for (int i = 0; i < a.size(); i ++) {
			if (a[i] + b[i] < k) return false;
		}
		return true;
	}
};