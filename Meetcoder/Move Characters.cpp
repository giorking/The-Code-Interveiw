class Solution {
public:
	void moveThem(char *s) {
        int len = strlen(s);
        int cur = len - 1;
        for (int i = len - 1; i >= 0; i --) {
            if (s[i] != ' ') {
                s[cur--] = s[i];
            }
        }
        while (cur >= 0) {
            s[cur--] = ' ';
        }
	}
};