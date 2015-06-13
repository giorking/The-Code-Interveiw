#include <iostream>
#include <cstring>

using namespace std;

long long dp[505][505][4];
long long map[505][505];

int main() {
	int m, n;
	cin >> m >> n;
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (map[j][1] != -1) {
				dp[j][1][i] = map[j][1];
			}
		}
	}
	/*for (int i = 1;i <= m; i ++) {
		for (int j = 0; j < 3; j ++) {
			cout << dp[i][1][j] << " ";
		}
		cout << endl;
	}*/
	long long res = -1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 3; j ++) {
			// up
			if (j == 0) {
				for (int k = m; k >= 1; k --) {
					if (k == 1) {
						if (dp[k][i][j] != -1 && map[m][i] != -1) {
							dp[m][i][j] = map[m][i];
						}
						if (dp[k][i][2] != -1 && map[m][i] != -1) {
							dp[m][i][j] = map[m][i];
						}
						continue;
					}
					if (dp[k][i][j] != -1 && map[k-1][i] != -1) {
						dp[k-1][i][j] = max(dp[k-1][i][j], dp[k][i][j] + map[k-1][i]);
						//if (dp[k][i][2] != -1) dp[k-1][i][j] = max(dp[k-1][i][j], dp[k][i][2] + map[k-1][i]);
					}
					if (dp[k][i][2] != -1 && map[k-1][i] != -1) {
						dp[k-1][i][j] = max(dp[k-1][i][j], dp[k][i][2] + map[k-1][i]);
					}
				}
			} else if (j == 1) {
				for (int k = 1; k <= m; k ++) {
					if (k == m) {
						if (dp[k][i][j] != -1 && map[1][i] != -1) {
							dp[1][i][j] = map[1][i];
						}
						if (dp[k][i][2] != -1 && map[1][i] != -1) {
							dp[1][i][j] = map[1][i];
						}
						continue;
					}
					if (dp[k][i][j] != -1 && map[k+1][i] != -1) {
						dp[k+1][i][j] = max(dp[k+1][i][j], dp[k][i][j] + map[k+1][i]);
					}
					if (dp[k][i][2] != -1 && map[k+1][i] != -1) {
						dp[k+1][i][j] = max(dp[k+1][i][j], dp[k][i][2] + map[k+1][i]);
					}
				}
			} else {
				for (int k = 1; k <= m; k ++) {
					if (map[k][i+1] == -1) continue;
					if (dp[k][i][j] != -1) {
						dp[k][i+1][j] = max(dp[k][i+1][j], dp[k][i][2] + map[k][i+1]);
					}
					if (dp[k][i][0] != -1) dp[k][i+1][j] = max(dp[k][i+1][j], dp[k][i][0] + map[k][i+1]);
					if (dp[k][i][1] != -1) dp[k][i+1][j] = max(dp[k][i+1][j], dp[k][i][1] + map[k][i+1]);
				}
			}
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < 3; j ++) {
			//cout << dp[i][n][j] << " ";
			res = max(res, dp[i][n][j]);
		}
		//cout << endl;
	}
	cout << res << endl;
	//system("pause");
	return 0;
}

/*
4 4
-1 4 4 1
-1 -1 -1 -1
-1 -1 -1 -1
2 3 1 -1

*/