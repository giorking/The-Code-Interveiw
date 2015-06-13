#include <cstdio>
#include <cmath>

long long cal(long long num) {
    return (num * num + num) * 2;
}

long long find_num(long long num) {
    long long left = 1, right = sqrt(num), mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        long long temp = cal(mid);
        if (cal(mid-1) < num && (temp >= num)) {
            return mid;
        } else if (temp < num) {
            left = mid + 1;
        } else if(temp > num) {
            right = mid - 1;
        }
    }
    return 0;
}

void solve(long long num, long long pos) {
    long long range = num * 4;
    if (pos <= range / 2) {
        if (pos == 0) printf("%lld 0\n", -num);
        else if(pos == range / 2) printf("0 %lld\n", -num);
        else {
            if (pos % 2 == 0) {
                printf("%lld %lld\n", -(num-pos/2), - pos/2);
            } else {
                printf("%lld %lld\n", -(num-pos/2), pos/2);
            }
        }
    } else {
        pos = pos - range / 2;
        if (pos == 0) printf("0 %lld\n", -num);
        else if(pos == range / 2) printf("%lld 0\n", num);
        else {
            if (pos % 2 == 0) {
                printf("%lld %lld\n", pos/2, -(num -pos/2));
            } else {
                printf("%lld %lld\n", pos/2,  (num - pos/2));
            }
        }
    }
}

int main() {
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i ++) {
        long long s;
        scanf("%lld", &s);
        if (s == 1) printf("0 0\n");
        else {
            long long num = find_num(s-1);
            printf("%lld\n", num);
            long long pos = s - 1 - cal(num - 1);
            solve(num, pos);
        }
    }
    return 0;
}