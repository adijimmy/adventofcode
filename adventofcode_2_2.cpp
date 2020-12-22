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

pair<int, int> getRange(string s) {
    stringstream ss(s);
    vector<string> v;
    string token;

    while (getline(ss, token, '-')) {
        v.push_back(token);
    }

    int l = stoi(v[0]);
    int r = stoi(v[1]);

    return make_pair(l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1000;
    int res = 0;
    string s;
    while (t--) {
        getline(cin, s);
        string token;
        stringstream ss(s);
        vector<string> arr;
        while (getline(ss, token, ' ')) {
            arr.push_back(token);
        }
        pair<int, int> range = getRange(arr[0]);
        char ch = arr[1][0];
        int cnt = 0;
        if (arr[2][range.first - 1] == ch) {
            cnt++;
        }
        if (arr[2][range.second - 1] == ch) {
            cnt++;
        }
        if (cnt == 1) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}