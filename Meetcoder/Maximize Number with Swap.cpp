class Solution {
public:
	int maximizeResult(int n) {
        int maxRes = n;
        string str = to_string(n);
        for (int i = 0; i < str.size(); i ++) {
            for (int j = i + 1; j < str.size(); j ++) {
                string n_str = str;
                char temp = n_str[i];
                n_str[i] = n_str[j];
                n_str[j] = temp;
                //swap(n_str[i], n_str[j]);
                maxRes = max(maxRes, stoi(n_str));
            }
        }
        return maxRes;
	}
};
