class Solution {
public:
	int leastDeletion(string &s) {
        int len = s.size();
        int r1 = 0, r2 = 0;
        char ch = '0';
        for (int i = 0; i < len; i ++) {
            if (s[i] != ch) {
                r1 ++;
            } else {
                ch = 1 - (ch - '0') + '0';
            }
        }
        ch = '1';
        for (int i = 0; i < len; i ++) {
            if (s[i] != ch) {
                r2 ++;
            } else {
                ch = 1 - (ch - '0') + '0';
            }
        }
        return min(r1, r2);
	}
};