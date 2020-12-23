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
    vector<ll> v;
    string s;
    while (getline(cin, s)) {
        v.push_back(stol(s));
    }
    sort(v.begin(), v.end());
    v.push_back(v[v.size() - 1] + 3);
    vector<int> cnt(4, 0);
    cnt[v[0]]++;
    for (int i = 1; i < v.size(); i++) {
        cnt[v[i] - v[i - 1]]++;
    }
    cout << cnt[1] * cnt[3] << endl;
    return 0;
}