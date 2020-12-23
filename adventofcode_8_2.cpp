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

int getValue(string s) {
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
    }
    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return neg ? -1 * res : res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    vector<string> command, value;
    int cnt = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            if (cnt % 2 == 0) command.push_back(token);
            else value.push_back(token);
            cnt++;
        }
    }
    int res = 0;
    for (int k = 0; k < command.size(); k++) {
        bool success = true;
        bool changed = false;
        int accumulator = 0;
        if (command[k] == "jmp") {
            command[k] = "nop";
            changed = true;
            vector<bool> visit(cnt, false);
            int i = 0;
            while (i < command.size()) {
                if (visit[i]) {
                    success = false;
                    break;
                }
                visit[i] = true;
                if (command[i] == "nop") {
                    i++;
                } else if (command[i] == "jmp") {
                    i += getValue(value[i]);
                } else {
                    accumulator += getValue(value[i]);
                    i++;
                }
            }
            command[k] = "jmp";
        } else if (command[k] == "nop") {
            command[k] = "jmp";
            changed = true;
            vector<bool> visit(cnt, false);
            int i = 0;
            while (i < command.size()) {
                if (visit[i]) {
                    success = false;
                    break;
                }
                visit[i] = true;
                if (command[i] == "nop") {
                    i++;
                } else if (command[i] == "jmp") {
                    i += getValue(value[i]);
                } else {
                    accumulator += getValue(value[i]);
                    i++;
                }
            }
            command[k] = "nop";
        }
        if (success && changed) {
            res = accumulator;
            break;
        }
    }
    cout << res << endl;
    return 0;
}