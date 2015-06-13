#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point{
    long long x, y;
};

long long labs(long long x){
    if (x > 0) return x;
    else return -x;
}

#define MAX 100010

int N;
Point node[MAX];
long long cost[MAX][MAX], d[MAX];
int used[MAX];

void dijk(int s) {
    d[s] = 0;
    while(true) {
        int v = -1;
        for (int u = 1; u <= N; u ++) {
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        used[v] = 1;
        for (int u = 1; u <= N; u++) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        //int x, y;
        //cin >> x >> y;
        //node[i].x = x;
        //node[i].y = y;
        cin >> node[i].x >> node[i].y;
    }
    //memset(cost, 0, sizeof(cost));
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= N; i ++ ) {
        for (int j = i + 1; j <= N; j ++) {
            cost[i][j] = cost[j][i] = min(labs(node[i].x-node[j].x), labs(node[i].y-node[j].y));
        }
        d[i] = min(labs(node[i].x-node[1].x), labs(node[i].y-node[1].y));
    }
    dijk(1);
    cout << d[N] << endl;
    return 0;
}