#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M;
int arr[100010], vis[100010];

void dfs(unordered_map<int, int>&st, unordered_map<int, vector<int> >&mp, int num) {
    if (st.find(num) == st.end()) return;
    st[num] = (st[num] + 1) % 142857;
    if (mp.find(num) == mp.end()) {
        return;
    } else {
        if (mp[num].size() > 0) {
            for (int i = 0; i < mp[num].size(); i ++) {
                //int res = st[mp[num][i]];
                //vis[res] = (vis[res] + 1) % 142857;
                dfs(st, mp, mp[num][i]);
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--) {
        memset(vis, 0, sizeof(vis));
        //map<int, int> tag;
        unordered_map<int, vector<int> >mp;
        unordered_map<int, int> st;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i ++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < N; i ++) {
            vector<int> vec;
            int x, y, z;
            scanf("%d%d", &x, &y);
            vis[i] = x;
            st[x] = 0;
            //tag[x] = 0;
            if (mp.find(x) != mp.end()) {
                for (int j = 0; j < y; j ++) {
                    scanf("%d", &z);
                    mp[x].push_back(z);
                }
            } else {
                for (int j = 0; j < y; j ++) {
                    scanf("%d", &z);
                    vec.push_back(z);
                }
                mp[x] = vec;
            }
        }
        for (int i = 0; i < M; i ++) {
            int start = arr[i];
            dfs(st, mp, start);
        }
        printf("%d", st[vis[0]]);
        for (int i = 1; i < N; i ++) {
            printf(" %d", st[vis[i]]);
        }
        printf("\n");
    }
    return 0;
}