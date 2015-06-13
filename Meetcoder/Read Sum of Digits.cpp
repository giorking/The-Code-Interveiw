class Solution {
public:
	string readSum(string &s) {
		string hash[10] =  {"zero","one","two","three","four","five","six","seven","eight","nine"};
		int sum = 0;
		for (int i = 0; i < s.length(); i ++) {
			sum += s[i] - '0';
		}
		string str = to_string(sum);
		string st = hash[str[0] - '0'];
		for (int i = 1; i < str.length(); i ++) {
			st += " ";
			st += hash[str[i] - '0'];
		}
		return st;
	}
};