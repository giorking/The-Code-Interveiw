#include <iostream>

using namespace std;

long long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
long long res,cnt;

void dfs(long long src,long long num,long long sum,long long up,long long index) {
    if(num > src) return;
    if(sum == cnt) {
        if (num < res) res = num;
    }
    if(sum > cnt) {
        cnt = sum;
        res = num;
    }
    long long cur = 1;
    for(long long i = 1; i <= up; i++) {
        cur *= prime[index];
        if(cur * num > src)  break;
        dfs(src, num * cur, sum * (i + 1), i, index + 1);
    }
}
int main() {
	long long src;
    cin >> src;
	cnt = 0;
	res = 0;
	if(src == 1){
		cout << src << endl;
		return 0;
	}
	dfs(src, 1, 1, 100, 0);
	cout << res << endl;
    return 0;
}