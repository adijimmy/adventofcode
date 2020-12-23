#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll getFact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 869;
    string s;
    int row, col;
    int res = -1;
    while (t--) {
        cin >> s;
        int lo = 0;
        int hi = 127;
        for (int i = 0; i < 7; i++) {
            int mid = (lo + hi) / 2;
            if (s[i] == 'F') {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        row = lo;
        lo = 0;
        hi = 7;
        for (int i = 7; i < 10; i++) {
            int mid = (lo + hi) / 2;
            if (s[i] == 'L') {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        col = lo;
        res = max(res, row * 8 + col);
    }
    cout << res << endl;
    return 0;
}