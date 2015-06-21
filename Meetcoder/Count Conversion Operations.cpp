class Solution {
public:
    int countOperations(int n) {
    	if (n == 0) return 0;
    	int cnt = 0;
    	while (n != 0) {
    		cnt += n % 2;
    		n = n / 2;
    		cnt ++;
    	}
    	return cnt - 1;
    }
};