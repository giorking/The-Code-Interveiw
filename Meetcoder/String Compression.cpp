#include <string>

class Solution {
public:
	string compressString(string &str){
        if (str.empty()) return str;
        string s = "";
        char cur = str[0];
        int num = 1;
        for (int i = 1; i < str.size(); i ++) {
            if (str[i] == str[i - 1]) {
                num ++;
            } else {
                s += cur;
                s += std::to_string(num);
                cur = str[i];
                num = 1;
            }
        }
        s += cur;
        s += std::to_string(num);
        if (s.length() < str.length()) return s;
        else return str;
	}
};