#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int map[105][105], backup[105][105];
int N, M, S;

struct P{
    int x, y;
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    cin >> N >> M >> S;
    memset(backup, -1, sizeof(backup));
    char ch;
    P a, b, c;
    for (int i = 1; i <= M; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> ch;
            backup[i][j] = ch - '0';
            if (backup[i][j] == 1) {
                a.x = i;
                a.y = j;
            } else if(backup[i][j] == 3) {
                b.x = i;
                b.y = j;
            } else if(backup[i][j] == 2) {
                c.x = i;
                c.y = j;
            }
        }
    }
    int res;
    string str;
    while (S--) {
        cin >> res >> str;
        memcpy(map, backup, sizeof(backup));
        int x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y, tag = 0, x3 = c.x, y3 = c.y;
        if (b.x == c.x && b.y == c.y) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i < str.size(); i ++) {
            int index = 0;
            if (str[i] == 'r') {
                index = 0;
            } else if (str[i] == 'l') {
                index = 1;
            } else if(str[i] == 'u') {
                index = 3;
            } else {
                index = 2;
            }
            int nx = x1 + dx[index], ny = y1 + dy[index];
            if (map[nx][ny] == 3) {
                int nx1 = nx + dx[index], ny1 = ny + dy[index];
                if (map[nx1][ny1] == 0 || map[nx1][ny1] == 2) {
                    map[x1][y1] = 0;
                    map[nx][ny] = 1;
                    map[nx1][ny1] = 3;
                    x1 = nx, y1 = ny, x2 = nx1, y2 = ny1;
                }
            } else {
                if (map[nx][ny] == 0 || map[nx][ny] == 2) {
                    map[x1][y1] = 0;
                    map[nx][ny] = 1;
                    x1 = nx, y1 = ny;
                }
            }
            if (x2 == x3 && y2 == y3) {
                tag = 1;
                break;
            }
        }
        if (tag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}