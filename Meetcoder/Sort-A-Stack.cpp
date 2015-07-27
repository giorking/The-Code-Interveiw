#include <stack>

class Solution {
public:
	stack<int> sortStack(stack<int> &s) {
        stack<int> cur;
        while (!s.empty()) {
            if (cur.empty() || s.top() >= cur.top()) {
                cur.push(s.top());
                s.pop();
            } else {
                int temp = s.top();
                s.pop();
                while (!cur.empty() && cur.top() > temp) {
                    s.push(cur.top());
                    cur.pop();
                }
                cur.push(temp);
            }
        }
        return cur;
	}
};