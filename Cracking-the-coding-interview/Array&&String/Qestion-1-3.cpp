#include <string>

bool permutation(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    int *vis = new int[256];
    for (int i = 0; i < str1.length(); i ++) {
        vis[str1[i]] ++;
    }
    for (int i = 0; i < str2.length(); i ++) {
        if (-- vis[str2[i]] < 0) return false;
    }
    return true;
}