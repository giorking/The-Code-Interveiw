#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool diff(int *arr, int *arr1) {
    for (int i = 0; i < 3; i ++) {
        if (arr[i] != arr1[i]) return false;
    }
    return true;
}

int abs(int x) {
    if (x > 0) return x;
    else return -x;
}

int arr[5], arr1[5];

int main(){
    string str;
    for (int i = 0; i < 3; i ++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);
    cin >> str;
    int res = 0, x1 = 0, y1 = 0, z1 = 0;
    for (int i = 0; i < str.size(); i ++) {
        if (str[i] == 'R') {
            x1 += 1;
        } else if (str[i] == 'Y') {
            y1 += 1;
        } else {
            z1 += 1;
        }
        arr1[0] = abs(z1-y1), arr1[1] = abs(x1-z1), arr1[2] = abs(y1-x1);
        sort(arr1, arr1+3);
        res = max(res, x1+y1+z1);
        if(diff(arr, arr1)) {
            x1 = y1 = z1 = 0;
        }
    }
    cout << res << endl;
    return 0;
}