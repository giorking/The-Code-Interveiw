#include <algorithm>

class Solution {
public:
    bool hasUniqueCharacters(char* s){
        int len = strlen(s);
        sort(s, s + len);
        for (int i = 0; i + 1 < len; i ++) {
            if (s[i] == s[i + 1]) return false;
        }
        return true;
    }
};
