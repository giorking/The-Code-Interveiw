#include <queue>

class Solution {
public:
    vector<int> mergeSortedArrays(vector<vector<int> > &a) {
        priority_queue<pair<int, pair<int, int> >,vector<pair<int,pair<int, int> > >,greater<pair<int,pair<int, int> > > >que;
        int k = a.size();
        for (int i = 0; i < k; i ++) {
            if(!a[i].empty()) que.push(make_pair(a[i][0], make_pair(i, 0)));
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top().first);
            int temp1 = que.top().second.first, temp2 = que.top().second.second;
            que.pop();
            if (temp2 + 1 < a[temp1].size()) {
                que.push(make_pair(a[temp1][temp2 + 1], make_pair(temp1, temp2 + 1)));
            }
        }
        return res;
    }
};

/**************************************************************
    Problem: 34
    User: iFighting
    Language: C++
    Result: Accepted
    Time:1450 ms
    Memory:39288 kb
****************************************************************/
