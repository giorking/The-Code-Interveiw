#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int bin[257];
int vis[30];

void init() {
    vis[1] = vis[2] = vis[3] = vis[5] = vis[8] = vis[13] = vis[21] = 1;
}

bool isfib(string str) {
    memset(bin, 0, sizeof(bin));
    int cnt = 0;
    for (int i = 0; i < str.size(); i ++) {
        if (bin[str[i]] == 0) {
            bin[str[i]] = 1;
            cnt ++;
        }
    }
    if (vis[cnt]) return true;
    else return false;
}

int main() {
    init();
    string str, s;
    cin >> str;
    vector<string> vec;
    set<string> st;
    for (int i = 0; i < str.size(); i ++) {
        for (int j = i; j < str.size(); j ++) {
            s = str.substr(i, j - i + 1);
            if (isfib(s) && st.find(s) == st.end()) {
                vec.push_back(s);
                st.insert(s);
            }
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i ++) {
        cout << vec[i] << endl;
    }
    return 0;
}

