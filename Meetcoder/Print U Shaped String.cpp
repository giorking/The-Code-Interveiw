class Solution {
public:
    vector<string> uFormat(string &s) {
        int len = s.size();
        int n1, n2, n3;
        if (len % 3 == 0) {
            n1 = n3 = len / 3 - 1;
        } else {
            n1 = n3 = len / 3;
        }
        n2 = len - n1 - n3;
        int left = 0, right = len - 1;
        vector<string> res;
        for (int i = 0; i < n1; i ++) {
            string str;
            str += s[left ++];
            for (int j = 0; j < n2 - 2; j ++) {
                str += " ";
            }
            str += s[right--];
            res.push_back(str);
        }
        string str;
        for (int i = left; i <= right; i ++) {
            str += s[i];
        }
        res.push_back(str);
        return res;
    }
};
/**************************************************************
    Problem: 11
    User: iFighting
    Language: C++
    Result: Accepted
    Time:2 ms
    Memory:1696 kb
****************************************************************/