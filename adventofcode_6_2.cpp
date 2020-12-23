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
    string line;
    int res = 0;
    vector<int> count(26, 0);
    int group_size = 0;
    while (getline(cin, line)) {
        if (line.length() == 0) {
            for (int i = 0; i < 26; i++) {
                if (count[i] == group_size) {
                    res++;
                }
                count[i] = 0;
            }
            group_size = 0;
            continue;
        }
        for (int i = 0; i < line.length(); i++) {
            int pos = line[i] - 'a';
            count[pos]++;
        }
        group_size++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] == group_size) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}