#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int maxv;

struct P{
    int a, b, c;
}p[1010];

int vis[1010];

void helper(int val, int time) {
    for (int i = 0; i < n; i ++) {
        if (vis[i] < k && time + p[i].c + 1 <= m) {
            vis[i] ++;
            int temp = p[i].a - time * p[i].b;
            maxv = max(maxv, temp + val);
            helper(temp + val, time + p[i].c);
            vis[i] --;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
        vis[i] = 0;
    }
    maxv = 0;
    helper(0, 0);
    cout << maxv << endl;
}