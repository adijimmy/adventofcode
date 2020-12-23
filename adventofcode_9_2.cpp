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

// 1 2 3 4 5
// 0 1 3 6 10 15

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<ll> v;
    string s;
    while (getline(cin, s)) {
        v.push_back(stol(s));
    }
    int n = v.size();
    vector<ll> cum_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cum_sum[i] = cum_sum[i - 1] + v[i - 1];
    }
    ll req_sum = 10884537;
    int l_idx, r_idx;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int l = i + 1;
            int r = j + 1;
            if (cum_sum[r] - cum_sum[l - 1] == req_sum) {
                l_idx = i;
                r_idx = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    ll mini = v[l_idx], maxi = v[r_idx];
    for (int i = l_idx + 1; i <= r_idx; i++) {
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }
    cout << mini + maxi << endl;
    return 0;
}