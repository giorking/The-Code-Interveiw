#include <string>


bool isUniqueChars(string str) {
    if (str.length() > 256) return false;
    bool *vis = new bool[256];
    for (int i = 0; i < str.length(); i ++) {
        if (vis[str[i]]) {
            delete []vis;
            return false;
        }
        vis[str[i]] = true;
    }
    delete []vis;
    return true;
}