#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void solve(vector<int> &num) {
    //using namespace std;
    set<int> st;
    int res = 1;
    for (int i = 0; i < num.size(); i ++){
        if (num[i] == res) {
            cout << num[i];
            res += 1;
            while(st.find(res) != st.end()) {
                st.erase(res);
                cout << "," << res;
                res += 1;
            }
            cout << endl;
        } else {
            st.insert(num[i]);
        }
    }
    while (!st.empty()) {
        cout << "," << res;
        st.erase(res);
        res ++;
    }
}

int main() {
    //using namespace std;
    int n;
    cin >> n;
    vector<int> vec;
    while (n--) {
        int res;
        cin >> res;
        vec.push_back(res);
    }
    solve(vec);
    return 0;
}
