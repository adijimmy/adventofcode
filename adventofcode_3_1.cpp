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

char s[323][31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 323;
    int m = 31;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    int row = 0, col = 0;
    int res = 0;
    while (row < n) {
        if (s[row][col] == '#') res++;
        row++;
        col += 3;
        col %= m;
    }
    cout << res << endl;
    return 0;
}