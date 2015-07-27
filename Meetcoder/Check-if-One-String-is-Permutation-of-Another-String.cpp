#include <string>
#include <algorithm>

class Solution {
public:
    bool isPermutation(string& a, string&b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b) return true;
        else return false;
    }
};